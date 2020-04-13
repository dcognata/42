<?php
require 'config/init.php';
require ROOT . '/app/App.php';

use Camagru\Controller\AppController;

App::load();

if (file_exists('./config/toInstall.txt'))
    header('Location: /config/setup.php');

if (isset($_GET['p']))
	$page = filter_var($_GET['p'], FILTER_SANITIZE_URL);
else
	$page = 'core.home';

$page = explode('.', $page);
$action = $page[1] . 'Action';
$controller = '\Camagru\Controller\\' . ucfirst($page[0]) . 'Controller';
$controller = new $controller();
if (method_exists($controller, $action)) {
    $controller->$action();
}
else
{
    $controller = new AppController();
	$controller->notFound();
}
?>
