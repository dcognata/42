<?php

use Core\Database\MysqlConnection;
use Core\Config;

/**
* 
*/
class App
{
	private static $_instance;
	private static $_database;

	public $title = ' - Camagru dcognata@42';

	public static function load()
	{
		session_start();
		require ROOT . '/app/Autoloader.php';
		Camagru\Autoloader::register();
        require ROOT . '/core/Autoloader.php';
		Core\Autoloader::register();
    }

	public static function getInstance()
	{
        if (is_null(self::$_instance))
			self::$_instance = new Self();
        return self::$_instance;
	}

	public static function getEntity($name)
	{
		$classname = 'Camagru\\Entity\\' . ucfirst($name);
		return new $classname(self::getDB());
	}

	public static function getDB()
	{
		if (null === self::$_database)
		{
	        $conf = Config::getInstance('/config/database.php');
			self::$_database = new MysqlConnection($conf->getValue('db_dsn'), $conf->getValue('db_user'), $conf->getValue('db_password'));
		}
		return self::$_database;
	}

	public static function getConn()
	{
		return self::getDB()->getConn();
	}

	public function setTitle($title)
	{
		$this->title = $title . $this->title;
		return $this->title;
	}

	public function getTitle()
	{
		return $this->title;
	}

	public function getAsset($asset)
	{
		return 'public/' . $asset;
	}

	public function forbidden()
	{
		header('HTTP/1.0 403 Forbidden');
		header('Location: index.php?p=core.home&msg=L\'accès à cet espace est réservé.');
	}

	public function redirect($location = 'core.home')
	{
		$url = 'http://' . $_SERVER['HTTP_HOST'] . str_replace('index.php', '', $_SERVER['SCRIPT_NAME']) . 'index.php?p=' . $location;

	    if (!headers_sent())
	        header('Location: '.$url);
	    else {
	        echo '<script type="text/javascript">';
	        echo 'window.location.href="'.$url.'";';
	        echo '</script>';
	        echo '<noscript>';
	        echo '<meta http-equiv="refresh" content="0;url='.$url.'" />';
	        echo '</noscript>';
	    }
	}

    public function is_ajax()
    {
        return (isset($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest');
    }

}
