<?php 

namespace Camagru\Utils;

/**
* 
*/
class Auth
{
	
	private $db;
	private $app;

	function __construct()
	{
		$this->app = \App::getInstance();;
		$this->db = $this->app->getDB();
	}

	public function getUserId()
	{
		if ($this->logged())
			return $_SESSION['auth'];
		return false;
	}

	public function getUsername()
	{
		if ($this->logged())
			return $_SESSION['username'];
		return false;
	}

	protected function createSession($user)
	{
		$userEntity = $this->app::getEntity('UserEntity');
		$userEntity->update($user->id, ['lastLogin' => date('Y-m-d H:i:s')]);

		$_SESSION['auth'] = $user->id;
		$_SESSION['username'] = $user->username;
		$_SESSION['mail'] = $user->email;
		$_SESSION['mailable'] = $user->mailable;
	}

	public function login($username, $password)
	{
		$username = htmlspecialchars($username);
		$user = $this->db->prepare(
			'SELECT id, username, password, email, activate, mailable FROM user WHERE username = ?', [$username], null, true
		);

		if ($user && $user->activate)
		{
			if (password_verify($password, $user->password))
			{
				$this->createSession($user);
			    return true;
			}
		}

	    return false;
	}

	public function logged()
	{	
		return isset($_SESSION['auth']);
	}

}

?>