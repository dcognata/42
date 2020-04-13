<div class="col-6 col-m-12">
  <h1>Connexion</h1>
  <?php if (!$auth->logged()) { ?>
    <form method="post">
    <?= $form->input('username', 'Nom',
        array(
            'icon' => 'fa fa-user',
            'maxlength' => 20,
            'required' => true
        ),
        $errorName,
        $successName
    ) ?>
    <?= $form->input('mail', 'Mail',
        array(
            'type' => 'email',
            'icon' => 'fa fa-envelope',
            'maxlength' => 255,
            'required' => true
        ),
        $errorMail,
        $successMail
    ) ?>
    <?= $form->input('password', 'Mot de passe',
        array(
            'type' => 'password',
            'icon' => 'fa fa-lock',
            'maxlength' => 60,
            'required' => true
        ),
        $errorPassword,
        $successPassword
    ) ?>
    <?= $form->input('password_check', 'Vérification',
        array(
            'type' => 'password',
            'icon' => 'fa fa-lock',
            'maxlength' => 60,
            'required' => true
        ),
        $errorPassword,
        $successPassword
    ) ?>
    <?= $form->token($errorToken) ?>
    <div class="field is-grouped">
      <div class="control">
        <button class="button is-primary" name="submit" value="true">Inscription</button>
      </div>
    </div>
    </form>
    <p>Vous avez un compte ? <a href="index.php?p=security.login">Connectez-vous</a> !</p>
  <?php } else { ?>
    <p>Vous êtes déjà connecté.</p>
  <?php } ?>
</div>