<!DOCTYPE html>
<html>
	<head>
		<title><?= $app->getTitle() ?></title>
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<link rel="shortcut icon" type="image/png" href="<?= $app->getAsset('images/fav.ico') ?>" />
		<link rel="stylesheet" type="text/css" href="<?= $app->getAsset('css/stylesheet.css') ?>">
		<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet">
		<script src="<?= $app->getAsset('js/jquery.js'); ?>" crossorigin="anonymous"></script>
	</head>
	<body>
		<div id="wrapper">
			<div id="content">
				<div class="header">
			        <span class="brand"><a href="index.php?p=core.home"><h1 class="white">Camagru</h1></a></span>
			        <span class="header-meta">
			        <?php if (!$auth->logged()) { ?>
				    	<p class="text-right"><a class="white" href="index.php?p=security.login">Connexion</a></p>
				    	<p class="text-right"><a class="white" href="index.php?p=security.register">Inscription</a></p>
				    <?php } else { ?>
				    	<p class="text-right">Bienvenue <a href="index.php?p=user.edit"><?= $auth->getUsername() ?></a></p>
				    	<p class="text-right"><a class="white" href="index.php?p=security.logout">Déconnexion</a></p>
				    <?php } ?>
			    	</span>
				</div>
				<div class="row">
					<?php if (isset($_GET['msg']) && !is_null($_GET['msg'])) { ?>
					<div class="col-12">
						<div class="alert">
						  <span class="closebtn" onclick="this.parentElement.style.display='none';">&times;</span> 
						  <?= htmlspecialchars($_GET['msg']) ?>
						</div>
					</div>
					<?php } ?>
					<div class="col-3 col-m-12 menu">
					  <ul>
					    <a class="white" href="index.php?p=core.home"><li>Accueil</li></a>
					    <a class="white" href="index.php?p=camagru.shoot"><li>Studio</li></a>
					    <a class="white" href="index.php?p=gallery.display"><li>Galerie</li></a>
				        <?php if ($auth->logged()) { ?>
				        <hr>
					    <a class="white" href="index.php?p=user.edit"><li>Mon compte</li></a>
					    <a class="white" href="index.php?p=security.logout"><li>Deconnexion</li></a>
					    <?php } ?>
					  </ul>
					</div>
					<?= $content ?>
				</div>
			</div>
		</div>
		<div class="footer">
			<p>Camagru - Une application par DCOGNATA.</p>
		</div>
		<script
		  src="https://code.jquery.com/jquery-3.3.1.min.js"
		  integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="
		  crossorigin="anonymous"></script>
	</body>
</html>
