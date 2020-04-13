<?php

namespace Core\Database;

use PDO;

/**
* 
*/
class MysqlConnection
{
    private $db;
    private $db_dsn;
    private $db_user;
    private $db_pass;

    public function __construct($db_dsn, $db_user, $db_pass)
    {
        $this->db_dsn  = $db_dsn;
        $this->db_user = $db_user;
        $this->db_pass = $db_pass;
    }

    public function getConn()
    {
        if (!$this->db)
        {
            try {
                $db = new PDO($this->db_dsn,  $this->db_user,  $this->db_pass);
                $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                $this->db = $db;
            } catch (PDOException $e) {
                echo 'Connexion échouée : ' . $e->getMessage();
            }
        }
        return $this->db;
    }

    public function query($repository, $classname = null, $one = false)
    {
        $query = $this->getConn()->query($repository);
        if (strpos($repository, 'UPDATE') === 0 || strpos($repository, 'INSERT') === 0 || strpos($repository, 'DELETE') === 0)
            return $query;

        if ($classname === null)
            $query->setFetchMode(PDO::FETCH_OBJ);
        else
            $query->setFetchMode(PDO::FETCH_CLASS, $classname);

        if ($one == true)
            return $query->fetch();
        return $query->fetchAll();
    }

    public function prepare($repository, $values, $classname = null, $one = true)
    {
        $query = $this->getConn()->prepare($repository);
        $query->execute($values);

        if (strpos($repository, 'UPDATE') === 0 || strpos($repository, 'INSERT') === 0 || strpos($repository, 'DELETE') === 0)
            return $query;

        if ($classname === null)
            $query->setFetchMode(PDO::FETCH_OBJ);
        else
            $query->setFetchMode(PDO::FETCH_CLASS, $classname);

        if ($one == true)
            return $query->fetch();
        return $query->fetchAll();
    }
}
