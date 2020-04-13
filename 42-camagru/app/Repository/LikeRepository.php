<?php

namespace Camagru\Repository;

use Core\Repository\Repository;

/**
* 
*/
class LikeRepository extends Repository
{
	public $id;
	public $picture_id;
	public $user_id;

	public function getId()
	{
		return $this->id;
	}

	public function getPicture()
	{
		return $this->picture_id;
	}

	public function setPicture($picture_id)
	{
		$this->picture_id = $picture_id;

		return $this->picture_id;
	}

	public function getUser()
	{
		return $this->user_id;
	}

	public function setUser($user_id)
	{
		$this->user_id = $user_id;

		return $this->user_id;
	}

}
