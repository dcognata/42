<?php

namespace Camagru\Repository;

use Core\Repository\Repository;

/**
* 
*/
class CommentRepository extends Repository
{
	public $id;
	public $picture_id;
	public $user_id;
	public $comment;
	public $published_at;

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

	public function getComment()
	{
		return $this->comment;
	}

	public function setComment($comment)
	{
		$this->comment = $comment;

		return $this->comment;
	}

	public function getPublishedAt()
	{
		return $this->published_at;
	}

	public function setPublishedAt($published_at)
	{
		$this->published_at = $published_at;

		return $this->published_at;
	}

}
