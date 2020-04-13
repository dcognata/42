<?php

namespace Camagru\Repository;

use Core\Repository\Repository;

/**
* 
*/
class PictureRepository extends Repository
{
	public $id;
	public $path;
	public $uploadAt;
	public $user_id;
	public $comments;
	public $likes;

	public function getId()
	{
		return $this->id;
	}

	public function getPath()
	{
		return $this->path;
	}

	public function setPath($path)
	{
		$this->path = $path;

		return $this->path;
	}

	public function getUploadAt()
	{
		return $this->uploadAt;
	}

	public function setUploadAt($uploadAt)
	{
		$this->uploadAt = $uploadAt;

		return $this->uploadAt;
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

	public function getComments()
	{
		return $this->comments;
	}

	public function setComments($comments)
	{
		$this->comments = $comments;

		return $this->comments;
	}

	public function getLikes()
	{
		return $this->likes;
	}

	public function setLikes($likes)
	{
		$this->likes = $likes;

		return $this->likes;
	}

}
