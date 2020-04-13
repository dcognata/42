<?php

require './init.php';

require ROOT . '/app/App.php';
App::load();

$conf = Core\Config::getInstance('/config/database.php');

$servername = $conf->getValue('db_host');
$username = $conf->getValue('db_user');
$password = $conf->getValue('db_password');
$database = $conf->getValue('db_name');

try {
    $conn = new \PDO("mysql:host=$servername", $username, $password);
    $conn->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);
    $sql = "DROP DATABASE IF EXISTS $database; CREATE DATABASE $database CHARACTER SET utf8 COLLATE utf8_general_ci;";
    $conn->exec($sql);
    echo "Database created successfully<br>";
} catch(PDOException $e) {
	echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "CREATE TABLE `camagru`.`user` ( `id` INT NOT NULL AUTO_INCREMENT , `username` VARCHAR(255) NOT NULL , `email` VARCHAR(255) NOT NULL , `mailable` BOOLEAN NOT NULL DEFAULT TRUE , `password` VARCHAR(255) NOT NULL , `token` VARCHAR(255) NOT NULL , `activate` BOOLEAN NOT NULL DEFAULT FALSE , `registerDate` DATETIME NOT NULL , `lastLogin` DATETIME NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;";
    $conn->exec($sql);
    echo "User table created successfully<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "CREATE TABLE `camagru`.`picture` ( `id` INT NOT NULL AUTO_INCREMENT , `path` VARCHAR(255) NOT NULL , `uploadAt` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP , `user_id` INT NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB CHARSET=utf8 COLLATE utf8_general_ci;";
    $conn->exec($sql);
    echo "Picture table created successfully<br>";
} catch(PDOException $e) {
	echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "ALTER TABLE `camagru`.`picture` ADD FOREIGN KEY (`user_id`) REFERENCES `camagru`.`user`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;";
    $conn->exec($sql);
    echo "Picture table liaison to user created successfully<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "ALTER TABLE `camagru`.`picture` ADD `comments` INT NOT NULL DEFAULT '0' AFTER `user_id`, ADD `likes` INT NOT NULL DEFAULT '0' AFTER `comments`;";
    $conn->exec($sql);
    echo "Picture table comment and like created successfully<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "INSERT INTO `camagru`.`user` (`id`, `username`, `email`, `password`, `token`, `activate`, `registerDate`, `lastLogin`) VALUES (NULL, 'admin', 'dcognata@student.42.fr', '$2y$13$1zQaCwlzy68gd2pFJmszLurHhLYRGYXVWtR2VHS.667/SdShGeaRi', 'admin', '1', '2018-10-01 00:00:00', NULL);";
    $conn->exec($sql);
    echo "Admin USER created<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "CREATE TABLE `camagru`.`like` ( `id` INT NOT NULL AUTO_INCREMENT , `picture_id` INT NOT NULL , `user_id` INT NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;";
    $conn->exec($sql);
    echo "Create Like Table<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "ALTER TABLE `camagru`.`like` ADD FOREIGN KEY (`user_id`) REFERENCES `user`(`id`) ON DELETE CASCADE ON UPDATE CASCADE; ALTER TABLE `like`;";
    $conn->exec($sql);
    $sql = "ALTER TABLE `camagru`.`like` ADD FOREIGN KEY (`picture_id`) REFERENCES `picture`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;";
    $conn->exec($sql);
    echo "Update relation Like Table<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

try {
    $sql = "CREATE TABLE `camagru`.`comment` ( `id` INT NOT NULL AUTO_INCREMENT , `picture_id` INT NOT NULL , `user_id` INT NOT NULL , `comment` TINYTEXT NOT NULL , `published_at` DATETIME NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;";
    $conn->exec($sql);
    $sql = "ALTER TABLE `camagru`.`comment` ADD FOREIGN KEY (`user_id`) REFERENCES `camagru`.`user`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;";
    $conn->exec($sql);
    $sql = "ALTER TABLE `camagru`.`comment` ADD FOREIGN KEY (`picture_id`) REFERENCES `camagru`.`picture`(`id`) ON DELETE CASCADE ON UPDATE CASCADE;";
    $conn->exec($sql);
    echo "Update Comment table<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

try {
    $query = $conn->prepare('SELECT id FROM camagru.user WHERE username = :value');
    if ($query->execute(array(':value' => 'admin')))
    {
        $query->setFetchMode(PDO::FETCH_OBJ);
        $user = $query->fetch();
    }
    $sql = [];
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-1.png', '2018-10-01 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-2.png', '2018-10-02 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-3.png', '2018-10-03 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-4.png', '2018-10-04 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-5.png', '2018-10-05 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-1.png', '2018-10-06 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-2.png', '2018-10-07 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-3.png', '2018-10-08 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-4.png', '2018-10-09 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-5.png', '2018-10-10 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-1.png', '2018-10-11 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-2.png', '2018-10-12 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-3.png', '2018-10-13 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-4.png', '2018-10-14 00:00:00', ".$user->id.", 0, 0)";
    $sql[] = "INSERT INTO `camagru`.`picture` (`id`, `path`, `uploadAt`, `user_id`, `comments`, `likes`) VALUES (NULL, '/images/def-5.png', '2018-10-15 00:00:00', ".$user->id.", 0, 0)";
    foreach ($sql as $key => $value) {
        $conn->exec($value);
    }
    echo "Images created<br>";
} catch(PDOException $e) {
    echo $sql . "<br>" . $e->getMessage();
}

unlink('./toInstall.txt');

$conn = null;
?>

Retourner a l'accueil : <a href="../index.php">ICI</a>