<div class="col-6 col-m-12">
  <h1>Modification du compte</h1>
  <?php if ($auth->logged()) { ?>
    <form method="post">
    <?= $form->input('username', 'Nom',
        array(
            'icon' => 'fa fa-user',
            'maxlength' => 20,
            'required' => false,
            'val' => $auth->getUsername(),
        ),
        $errorName,
        $successName
    ) ?>
    <?= $form->input('mail', 'Mail',
        array(
            'type' => 'email',
            'icon' => 'fa fa-envelope',
            'maxlength' => 255,
            'required' => false,
            'val' => $user->email,
        ),
        $errorMail,
        $successMail
    ) ?>
    <?= $form->input('new_password', 'Nouveau mot de passe',
        array(
            'type' => 'password',
            'icon' => 'fa fa-lock',
            'maxlength' => 60,
            'required' => false
        ),
        $errorPassword,
        $successPassword
    ) ?>
    <?= $form->input('check_password', 'Confirmation mot de passe',
        array(
            'type' => 'password',
            'icon' => 'fa fa-lock',
            'maxlength' => 60,
            'required' => false
        )
    ) ?>
    <?= $form->checkbox('mailable', 'Voulez-vous recevoir des mails du site ?',
        array(
            'required' => false,
            'val' => $user->mailable,
        ),
        $errorMailable,
        $successMailable
    ) ?>
    <hr>
    <?= $form->input('old_password', 'Ancien mot de passe',
        array(
            'type' => 'password',
            'icon' => 'fa fa-unlock',
            'maxlength' => 60,
            'required' => true,
        ),
        $errorOldPassword,
        $successOldPassword
    ) ?>
    <?= $form->token($errorToken) ?>
    <div class="field is-grouped">
      <div class="control">
        <button class="button is-primary" name="submit" value="true">Connexion</button>
      </div>
    </div>
    </form>
  <?php } else { ?>
    <p>Vous êtes déjà connecté.</p>
  <?php } ?>
</div>