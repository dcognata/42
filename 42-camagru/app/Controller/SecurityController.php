<?php
namespace Camagru\Controller;

use \Core\Form\Form;
use \Core\Mail\Mailer;

/**
 *
 */
class SecurityController extends AppController
{

    public function __construct()
    {
        parent::__construct();
        $this->loadModel('User');
    }

    /**
     * Login form for access
     */
    public function loginAction()
    {
        $this->app->setTitle('Connexion');

        $form = new Form($_POST);

        $errorName = null;
        $errorPassword = null;
        $success = null;
        $errorToken = null;
        if (!empty($_POST['submit']) && $_POST['submit'] == 'true') {
            $calc = hash_hmac('sha256', 'hashedForm', $_SESSION['token']);
            if (hash_equals($calc, $_POST['token'])) {
                if ($this->auth->login($_POST['username'], $_POST['password'])) {
                    $this->app->redirect('core.home');
                } else {
                    $errorName = 'Informations de connexion erronée<br>';
                    $errorPassword = 'Informations de connexion erronée<br>';
                    if (empty($_POST['username']))
                        $errorName = 'Vous devez renseigner cette donnée<br>';
                    if (empty($_POST['password']))
                        $errorPassword = 'Vous devez renseigner cette donnée<br>';
                }
            } else {
                $errorToken = true;
            }
        }

        $this->render('security.login', compact(
            'form',
            'errorName', 'errorPassword', 'errorToken', 'success'
        ));
    }

    /**
     * Logout user
     */
    public function logoutAction()
    {
        if(!isset($_SESSION))
            session_start();
        $_SESSION = array();
        if (ini_get("session.use_cookies")) {
            $params = session_get_cookie_params();
            setcookie(session_name(), '', time() - 42000,
                $params["path"], $params["domain"],
                $params["secure"], $params["httponly"]
            );
        }
        session_destroy();
        header('Location: index.php?msg=Vous avez bien été déconnecté, à bientôt.');
    }

    /**
     * Register form for access
     */
    public function registerAction()
    {
        $this->app->setTitle('Inscription');

        $errorName = null;
        $errorMail = null;
        $errorPassword = null;
        $successName = null;
        $successMail = null;
        $successPassword = null;
        $errorToken = null;
        if (!empty($_POST['submit']) && $_POST['submit'] == 'true') {
            $calc = hash_hmac('sha256', 'hashedForm', $_SESSION['token']);
            if (hash_equals($calc, $_POST['token'])) {

                $userEntity = $this->UserEntity;

                $username = filter_var(htmlspecialchars($_POST['username']), FILTER_SANITIZE_STRING);
                $mail = filter_var(htmlspecialchars(strtolower($_POST['mail'])), FILTER_SANITIZE_EMAIL);
                $password = $_POST['password'];
                $passwordCheck = $_POST['password_check'];

                $errorName = $this->validUsername($username, $userEntity);
                if (!$errorName)
                    $successName = 'Le nom est valide.';

                $errorPassword = $this->validPassword($password, $passwordCheck);
                if (!$errorPassword)
                    $successPassword = 'Le mot de passe est valide.';

                $errorMail = $this->validEmail($mail, $userEntity);
                if (!$errorMail)
                    $successMail = 'L\'adresse est valide.';

                if ($errorName == null && $errorMail == null && $errorPassword == null)
                {
                    $hash = password_hash($password, PASSWORD_BCRYPT, [
                        'cost' => 13
                    ]);
                    $token = bin2hex(random_bytes(10));
                    $registerDate = date('Y-m-d H:i:s');

                    $userEntity->create([
                        'username' => $username,
                        'email' => $mail,
                        'password' => $hash,
                        'token' => $token,
                        'registerDate' => $registerDate
                    ]);

                    $url = 'http://' . $_SERVER['HTTP_HOST'] . str_replace("/index.php?p=security.register", "/index.php?p=security.validate&token=$token", $_SERVER['REQUEST_URI']);

                    $mail = new Mailer($mail, 'Inscription',
                        "Vous venez de vous inscrire sur camagru.<br><br>
			            Pour confirmer votre compte, suivez ce lien :<br>
			            $url"

                    );
                    $mail->sendMail();

                    header('Location: index.php?p=core.home&msg=Votre compte a été enregistré, veuillez valider votre compte avec le lien communiqué par mail.');
                }
            } else {
                $errorToken = true;
            }
        }

        $form = new Form($_POST);

        $this->render('security.register', compact(
            'form',
            'errorName', 'errorMail', 'errorPassword',
            'successName', 'successMail', 'successPassword', 'errorToken'
        ));
    }

    /**
     * Resetting the password
     */
    public function resettingAction()
    {
        $this->app->setTitle('Réinitialiser');

        $success = null;
        $errorName = null;
        $errorToken = null;
        $form = new Form($_POST);
        if (!empty($_POST['submit']) && $_POST['submit'] == 'true') {
            $calc = hash_hmac('sha256', 'hashedForm', $_SESSION['token']);
            if (hash_equals($calc, $_POST['token'])) {
                if (!isset($_POST['username'])) {
                    $errorName = 'Vous devez renseigner un nom d\'utilisateur';
                    header('Location: index.php');
                } else {
                    $username = htmlspecialchars($_POST['username']);
                    $user = $this->UserEntity->findOneBy('username', $username);
                    if ($user)
                    {
                        $url = 'http://' . $_SERVER['HTTP_HOST'] . str_replace("/index.php?p=security.resetting", "/index.php?p=security.resettingChange&token=$user->token", $_SERVER['REQUEST_URI']);

                        $mail = new Mailer($user->email, 'Mot de passe',
                            "Vous venez de faire une demande pour changer votre mot de passe.<br><br>
							Suivez ce lien pour poursuivre:<br>
							$url"
                        );
                        $mail->sendMail();

                    }
                    $success = 'Un mail a été envoyé à l\'adresse mail de ce compte';
                }
            } else {
                $errorToken = true;
            }
        }

        $this->render('security.resetting', compact(
            'form',
            'errorName', 'success', 'errorToken'
        ));
    }

    /**
     * resettingChange the password
     */
    public function resettingChangeAction()
    {
        $this->app->setTitle('Réinitialiser');

        $token = $_GET['token'];

        $errorName = null;
        $errorPassword = null;
        $successName = null;
        $successPassword = null;
        $errorToken = null;
        $form = new Form($_POST);
        if (!empty($_POST['submit']) && $_POST['submit'] == 'true') {
            $calc = hash_hmac('sha256', 'hashedForm', $_SESSION['token']);
            if (hash_equals($calc, $_POST['token'])) {
                $username = htmlspecialchars($_POST['username']);
                $password = $_POST['password'];
                $passwordCheck = $_POST['password_check'];
                $userEntity = $this->UserEntity;

                $errorName = $this->checkUsername($username, $token, $userEntity);
                if (is_null($errorName))
                    $successName = 'Utilisateur valide.';

                $errorPassword = $this->validPassword($password, $passwordCheck);
                if (is_null($errorPassword))
                    $successPassword = 'Le mot de passe est valide.';

                if ($errorName == null && $errorPassword == null)
                {
                    $this->change_password($userEntity, $username, $password);
                    header('Location: index.php?p=security.login&msg=Votre mot de passe a été modifié.');
                }
            } else {
                $errorToken = true;
            }
        }

        $this->render('security.resetting_change', compact(
            'form',
            'errorName', 'errorPassword',
            'successName', 'successPassword',
            'token', 'errorToken'
        ));
    }

    /**
     * Validate the account
     */
    public function validateAction()
    {
        $this->app->setTitle('Valider');

        if (isset($_GET['token']))
        {
            $token = htmlspecialchars($_GET['token']);
            $userEntity = $this->UserEntity;
            $user = $userEntity->findOneBy('token', $token);
            if ($user)
            {
                $userEntity->update($user->id, ['activate' => true]);
                header('Location: index.php?p=security.login&msg=Le compte a bien été validé.');
            }
            else
                header('Location: index.php?p=core.home&msg=Le token ne correspond à aucun compte.');
        }
    }

    private function change_password($userEntity, $username, $password)
    {
        $user = $userEntity->findOneBy('username', $username);
        $hash = password_hash($password, PASSWORD_BCRYPT, [
            'cost' => 13
        ]);
        $token = bin2hex(random_bytes(10));

        $userEntity->update($user->id, [
            'password' => $hash,
            'token' => $token,
        ]);
    }

    private function checkUsername($username, $token, $userEntity)
    {
        $message = null;
        if (!$username)
            $message = 'Le nom d\'utilisateur doit-être renseigné';

        $user = $userEntity->findOneBy('token', $token);
        if ($user->username === $username)
            return null;
        else
            $message = 'L\'utilisateur n\'existe pas';
        return $message;
    }

    private function validPassword($password, $passwordCheck)
    {
        $message = null;
        if (!$password || !$passwordCheck)
            $message = 'Le mot de passe doit-être renseigné';
        else
        {
            $passLen = strlen($password);
            if ($password !== $passwordCheck)
            {
                $message = 'Les mots de passe ne sont pas les même';
                return $message;
            }
            if ($passLen < 8)
                $message = 'Le mot de passe doit faire plus de 7 caractères';
            else if ($passLen > 60)
                $message = 'Le mot de passe doit faire moins de 60 caractères';
            else
            {
                if(preg_match('/[A-Z]+/', $passwordCheck) && preg_match('/[a-z]+/', $passwordCheck) && preg_match('/[\d!$%^&]+/', $passwordCheck))
                    return null;
                else
                    $message = 'Le mot de passe doit contenir une lettre majuscule et un chiffre au minimum';
            }

        }
        return $message;
    }

    private function validEmail($email, $userEntity)
    {
        $message = null;
        $atIndex = strrpos($email, "@");

        if (empty($email)) {
            $message = 'Le mail doit-être renseigné';
        } else {
            if (is_bool($atIndex) && !$atIndex)
                $message = 'L\'adresse adresse mail n\'est pas valide';
            else {
                if ($userEntity->findOneBy('email', $email)) {
                    return 'Le mail est déjà utilisé';
                } else {
                    $domain = substr($email, $atIndex+1);
                    $local = substr($email, 0, $atIndex);
                    $localLen = strlen($local);
                    $domainLen = strlen($domain);

                    if ($localLen < 1 || $localLen > 64)
                        $message = 'L\'adresse adresse mail n\'est pas valide';
                    else if ($domainLen < 1 || $domainLen > 255)
                        $message = 'L\'adresse adresse mail n\'est pas valide';
                    else if ($local[0] == '.' || $local[$localLen-1] == '.')
                        $message = 'L\'adresse adresse mail n\'est pas valide';
                    else if (preg_match('/\\.\\./', $local))
                        $message = 'L\'adresse adresse mail n\'est pas valide';
                    else if (!preg_match('/^[A-Za-z0-9\\-\\.]+$/', $domain))
                        $message = 'L\'adresse adresse mail n\'est pas valide';
                    else if (preg_match('/\\.\\./', $domain))
                        $message = 'L\'adresse adresse mail n\'est pas valide';
                    else if (!preg_match('/^(\\\\.|[A-Za-z0-9!#%&`_=\\/$\'*+?^{}|~.-])+$/', str_replace("\\\\","",$local)))
                        if (!preg_match('/^"(\\\\"|[^"])+"$/', str_replace("\\\\","",$local)))
                            $message = 'L\'adresse adresse mail n\'est pas valide';

                    if (!(checkdnsrr($domain,"MX") || checkdnsrr($domain,"A")))
                        $message = 'L\'adresse adresse mail n\'est pas valide';
                    if (!filter_var($email, FILTER_VALIDATE_EMAIL))
                        $message = "$email n'est pas considérée comme valide.";
                }
            }
        }
        return ($message);
    }

    private function validUsername($username, $userEntity)
    {
        $message = null;
        if (!$username)
            $message = 'Le nom d\'utilisateur doit-être renseigné';

        if ($userEntity->findOneBy('username', $username))
            return 'Le nom d\'utilisateur n\'est pas disponible';
        else
        {
            $userLen = strlen($username);
            if ($userLen < 3)
                $message = 'Le nom d\'utilisateur doit faire plus de 3 caractères';
            else if ($userLen > 20)
                $message = 'Le nom d\'utilisateur doit faire moins de 20 caractères';
            else
            {
                if(preg_match('/^[a-zA-Z]+[a-zA-Z0-9._]+$/', $username))
                    return null;
                else
                    $message = 'Le nom d\'utilisateur doit être composé de caractères Alphanumériques';
            }

        }
        return $message;
    }
}