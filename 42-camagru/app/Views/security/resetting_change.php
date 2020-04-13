<div class="col-6 col-m-12">
  <h1>Réinitialisation</h1>
  <?php if (!$auth->logged() && !is_null($token)) { ?>
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
    <?= $form->input('password', 'Nouveau mot de passe',
        array(
            'type' => 'password',
            'icon' => 'fa fa-lock',
            'maxlength' => 20,
            'required' => true
        ),
        $errorPassword,
        $successPassword
    ) ?>
    <?= $form->input('password_check', 'Verification mot de passe',
        array(
            'type' => 'password',
            'icon' => 'fa fa-lock',
            'maxlength' => 20,
            'required' => true
        ),
        $errorPassword,
        $successPassword
    ) ?>
    <?= $form->token($errorToken) ?>
    <div class="field is-grouped">
      <div class="control">
        <button class="button is-primary" name="submit" value="true">Réinitialiser</button>
      </div>
    </div>
    </form>
    <p>Vous n'avez pas de compte ? <a href="index.php?p=security.register">Créez en un</a> !</p>
    <p><a href="index.php?p=security.resetting">Mot de passe oublié</a> ?</p>
  <?php } else if (is_null($token)) { ?>
    <p>Vous n'avez pas de token valide.</p>
  <?php } else { ?>
    <p>Vous êtes déjà connecté.</p>
  <?php } ?>
</div>