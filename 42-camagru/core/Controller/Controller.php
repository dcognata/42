<?php

namespace Core\Controller;

/**
* 
*/
class Controller
{

	protected $viewPath;
	protected $template;
	protected $app;
	protected $auth;

	public function __construct()
	{
		$this->app = \App::getInstance();
		$this->auth = new \Camagru\Utils\Auth();
	}

	protected function render($view, $variables = [])
	{

        $app = $this->app;
		$auth = $this->auth;

		ob_start();
		if (!is_null($variables))
			extract($variables);
		require($this->viewPath . str_replace('.', '/', $view) . '.php');
		$content = ob_get_clean();
		require($this->viewPath . 'template/' . $this->template . '.php');
	}

	public function forbidden()
	{
		header('HTTP/1.0 403 Forbidden');
		die('Accès interdit');
	}

	public function notFound()
	{
		header('HTTP/1.0 404 Not Found');
		die('Page introuvable');
	}

}

?>