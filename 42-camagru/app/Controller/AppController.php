<?php

namespace Camagru\Controller;

use Core\Controller\Controller;

/**
* 
*/
class AppController extends Controller
{
	protected $viewPath;
	protected $template = 'default';

	public function __construct()
	{
		parent::__construct();
        $this->viewPath = ROOT . 'app/Views/';
	}

	public function notFound()
	{
		$this->app->setTitle('404');

		$this->render('error');
	}

	protected function loadModel($model_name)
	{
		$model_name = $model_name . 'Entity';
		$this->$model_name = $this->app->getEntity($model_name);
	}
}

?>