<?php

namespace Camagru\Entity;

use Core\Entity\Entity;

/**
* 
*/
class LikeEntity extends Entity
{
	public function findByUserAndPicture($user, $picture)
	{
        $statement = 'SELECT * FROM `'. $this->table .'` WHERE user_id = ? AND picture_id = ?';
        return $this->query($statement, [$user, $picture], true);
	}
}
