<?php

class Installator
{
	public $db_dns;
	public $db_user;
	public $db_password;
	public $db_name;
	public $db_host;

	public function firstInstructions()
	{

		printf("Camagru :\n");
		printf("---------\n");
		printf("Nous allons proceder a l'installation des donnees necessaire au fonctionnement du site.\n");

		printf("\nImages :\n");
		printf("Copie des images pour le jeu de donnees par defaut.\n");
		shell_exec('cp config/backup/images/def-1.png config/backup/images/def-2.png config/backup/images/def-3.png config/backup/images/def-4.png config/backup/images/def-5.png config/backup/images/def-6.png public/images/');

		printf("\nMoteur :\n");
		printf("Ajout du fichier de configuration.\n");
		shell_exec('cp config/backup/toInstall.txt config/toInstall.txt');

	}

	public function initDB()
	{

		printf("\nConfiguration Database :\n");
		$this->db_dns = 
			(($db_dns = readline('$db_dns (mysql:dbname=camagru;host=127.0.0.1) = ')) == "") ? "mysql:dbname=camagru;host=127.0.0.1" : $db_dns;
		$this->db_user = 
			(($db_user = readline('$db_user (root) = ')) == "") ? "root" : $db_user;
		$this->db_password = 
			(($db_password = readline('$db_password (root) = ')) == "") ? "root" : $db_password;
		$this->db_name = 
			(($db_name = readline('$db_name (camagru) = ')) == "") ? "camagru" : $db_name;
		$this->db_host = 
			(($db_host = readline('$db_host (127.0.0.1) = ')) == "") ? "127.0.0.1" : $db_host;

		printf("\nconfig/database.php :\n<?php
\$DB_DSN = '".$this->db_dns."';
\$DB_USER = '".$this->db_user."';
\$DB_PASSWORD = '".$this->db_password."';
\$DB_NAME = '".$this->db_name."';
\$DB_HOST = '".$this->db_host."';
?>\n");

		if (($v = readline("La configuration est-elle correcte ? (y/n) ")) == 'y' || $v == "")
			return true;
		else
			return false;

	}

	public function generateDatabaseConfig()
	{
		shell_exec('cp config/database.php config/database.inc.php');

		if (!($fp = fopen('config/database.php', 'w'))) {
		    return;
		}

		fprintf($fp, "<?php
\$DB_DSN = '".$this->db_dns."';
\$DB_USER = '".$this->db_user."';
\$DB_PASSWORD = '".$this->db_password."';
\$DB_NAME = '".$this->db_name."';
\$DB_HOST = '".$this->db_host."';
?>");

	}
}

$installator = new Installator;

$installator->firstInstructions();
while (!$installator->initDB())
	$installator->initDB();
$installator->generateDatabaseConfig();

printf("\n Vous allez etre redirige sur http://localhost/config/setup.php pour initialiser la base de donnees.\n");
sleep(3);
shell_exec('open "http://localhost/config/setup.php"');

?>