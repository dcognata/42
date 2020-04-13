<?php

namespace Core;

/**
* 
*/
class Config
{
	private static $_instance;
	private $settings = [];

	public function __construct($file)
	{
		require ROOT . $file;
		if ($DB_DSN && $DB_USER && $DB_PASSWORD)
		{
			$this->settings = [
				'db_dsn' => $DB_DSN,
				'db_user' => $DB_USER,
				'db_password' => $DB_PASSWORD,
				'db_name' => $DB_NAME,
				'db_host' => $DB_HOST,
			];
		}
	}

	public static function getInstance($file)
	{
		if (is_null(self::$_instance))
			self::$_instance = new Self($file);
		return self::$_instance;
	}

	public function getValue($key)
	{
		if (isset($this->settings[$key]))
			return $this->settings[$key];
		return null;
	}
}
