<?php

namespace Camagru\Entity;

use Core\Entity\Entity;

/**
* 
*/
class PictureEntity extends Entity
{
	public function findLast($limit = 0)
    {
        $statement = 'SELECT * FROM '. $this->table .' ORDER BY uploadAt DESC';
        if ($limit > 0)
            $statement .= ' LIMIT ' . $limit .'';
        return $this->query($statement);
    }


    public function findByUser($user, $limit = 0)
    {
        $statement = 'SELECT * FROM `'. $this->table .'` WHERE user_id = ? ORDER BY uploadAt DESC';
        if ($limit > 0)
            $statement .= ' LIMIT ' . $limit .'';
        return $this->query($statement, [$user]);
    }

    public function findOffset($start, $to)
    {
        $statement = "SELECT p.id, p.path, p.user_id, p.comments, p.likes FROM ".$this->table." as p ORDER BY uploadAt DESC LIMIT $start OFFSET $to";
        return $this->query($statement);
    }
}
