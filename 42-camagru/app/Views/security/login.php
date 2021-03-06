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
        $success
    ) ?>
    <?= $form->input('password', 'Mot de passe',
        array(
            'type' => 'password',
            'icon' => 'fa fa-lock',
            'maxlength' => 60,
            'required' => true
        ),
        $errorPassword,
        $success
    ) ?>
    <?= $form->token($errorToken) ?>
    <div class="field is-grouped">
      <div class="control">
        <button class="button is-primary" name="submit" value="true">Connexion</button>
      </div>
    </div>
    </form>
    <p>Vous n'avez pas de compte ? <a href="index.php?p=security.register">Créez en un</a> !</p>
    <p><a href="index.php?p=security.resetting">Mot de passe oublié</a> ?</p>
  <?php } else { ?>
    <p>Vous êtes déjà connecté.</p>
  <?php } ?>
</div>