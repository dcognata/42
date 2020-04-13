<div class="col-6 col-m-9">
  <h1>Studio Camagru</h1>
  <?php if (!$auth->logged()) { ?>
    <p>Vous devez être connecté pour accéder à toutes les fonctionnalités du studio camagru.</p>
  <?php } ?>
  <div class="row">
    <?php foreach ($lastPictures as $key => $picture) { ?>
    <div class="col-4 col-m-12">
      <div class="card">
        <img class="img-fluid" src="<?= $app->getAsset($picture->path) ?>">

      </div>
    </div>
    <?php } ?>
  </div>
  <p><a href="index.php?p=gallery.display">Voir toutes les photos</a></p>
</div>

<div class="col-3 col-m-12">
  <div class="aside">
    <h2>What?</h2>
    <p>Ce projet vous propose de créer une petite application web permettant de réaliser des montages basiques à l’aide de votre webcam et d’images prédéfinies.</p>
  </div>
</div>
