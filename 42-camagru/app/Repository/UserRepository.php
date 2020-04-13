<?php

namespace Camagru\Repository;

use Core\Repository\Repository;

/**
* 
*/
class UserRepository extends Repository
{
	public $id;
	public $username;
	public $email;
	public $mailable;
	public $password;
	public $token;
	public $registerDate;
	public $lastLogin;

	public function getId()
	{
		return $this->id;
	}

	public function getUsername()
	{
		return $this->username;
	}

	public function setUsername($username)
	{
		$this->username = $username;

		return $this->username;
	}

	public function getEmail()
	{
		return $this->email;
	}

	public function setEmail($email)
	{
		$this->email = $email;

		return $this->email;
	}

	public function getMailable()
	{
		return $this->mailable;
	}

	public function setMailable($mailable)
	{
		$this->mailable = $mailable;

		return $this->mailable;
	}

	public function getPassword()
	{
		return $this->password;
	}

	public function setPassword($password)
	{
		$this->password = $password;

		return $this->password;
	}

	public function getToken()
	{
		return $this->token;
	}

	public function setToken($token)
	{
		$this->token = $token;

		return $this->token;
	}

	public function getRegisterDate()
	{
		return $this->registerDate;
	}

	public function setRegisterDate($registerDate)
	{
		$this->registerDate = $registerDate;

		return $this->registerDate;
	}

	public function getLastLogin()
	{
		return $this->lastLogin;
	}

	public function setLastLogin($lastLogin)
	{
		$this->lastLogin = $lastLogin;

		return $this->lastLogin;
	}
}
