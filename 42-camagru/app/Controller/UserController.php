<?php

namespace Camagru\Controller;

use \Core\Form\Form;
use \Core\Mail\Mailer;

/**
* 
*/
class UserController extends AppController
{

	public function __construct()
	{
		parent::__construct();
		$this->loadModel('User');
	}

	/**
	* Validate the account
	*/
	public function editAction()
	{
	    $this->app->setTitle('Modification compte');

    	$userEntity = $this->UserEntity;
        if (($user = $userEntity->findOneBy('username', $_SESSION['username'])) != null) {
		    $errorName = null;
		    $errorMail = null;
		    $errorOldPassword = null;
		    $errorPassword = null;
		    $errorMailable = null;
		    $successName = null;
		    $successMail = null;
		    $successOldPassword = null;
		    $successPassword = null;
		    $successMailable = null;
			$errorToken = null;
			$form = new Form($_POST);
	        if (!empty($_POST['submit']) && $_POST['submit'] == 'true') {
				$calc = hash_hmac('sha256', 'hashedForm', $_SESSION['token']);
				if (hash_equals($calc, $_POST['token'])) {
					$userEntity = $this->UserEntity;

			        $username = filter_var(htmlspecialchars($_POST['username']), FILTER_SANITIZE_STRING);
			        $mail = filter_var(htmlspecialchars(strtolower($_POST['mail'])), FILTER_SANITIZE_EMAIL);
			        $oldPassword = $_POST['old_password'];
			        $newPassword = $_POST['new_password'];
			        $checkPassword = $_POST['check_password'];
			        $mailable = (array_key_exists('mailable', $_POST)) ?  '1' : '0';

			        if (strlen($oldPassword) > 0 && password_verify($oldPassword, $user->password))
			        {
				        if (strlen($username) > 0 && $username != $user->username) {
					        $errorName = $this->validUsername($username, $userEntity);
					        if (!$errorName) {
					            $successName = 'Le nom a été enregistrée.';
					            $_SESSION['username'] = $username;
								$userEntity->update($user->id, [
									'username' => $username,
								]);
					        }
				        }

				        if (strlen($mail) > 0 && $mail != $user->email) {
					        $errorMail = $this->validEmail($mail, $userEntity);
					        if (!$errorMail) {
					            $successMail = 'L\'adresse a été enregistrée.';
								$userEntity->update($user->id, [
									'email' => $mail,
								]);
					        }
				        }

				        if (strlen($checkPassword) > 0 && strlen($newPassword) > 0) {
							$errorPassword = $this->validPassword($newPassword, $checkPassword);
							if (is_null($errorPassword)) {
								$this->change_password($userEntity, $username, $newPassword);
								$successPassword = 'Le mot de passe a été enregistré.';
							}
				        }

				        if ($mailable != $user->mailable)
				        {
	                        $userEntity->update($user->id, [
	                            'mailable' => $mailable,
	                        ]);
	                        $_SESSION['mailable'] = $mailable;
	                        $successMailable = 'Votre gestion des mails a ete modifiee.';
				        }

				        if (!$errorMail && !$errorName && !$errorPassword)
							$user = $userEntity->findOneBy('username', $_SESSION['username']);
				    } else {
				    	$errorOldPassword = "Merci de renseigner votre mot de passe actuel.";
				    }
				} else {
					$errorToken = true;
				}
		    }
        } else {
        	$this->app->forbidden();
        }

        if ($successName != null || $successMail != null || $successPassword != null || $successMailable != null)
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
            header('Location: index.php?p=security.login&msg=Vos modifications ont ete appliquees, veuillez vous reconnecter.');
        }

		$this->render('security.edit', compact(
			'form', 'user',
			'errorName', 'errorMail', 'errorOldPassword', 'errorPassword', 'errorMailable',
			'successName', 'successMail', 'successOldPassword', 'successPassword', 'successMailable', 'errorToken'
		));
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
?>