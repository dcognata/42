<?php

namespace Camagru\Controller;

/**
* 
*/
class CoreController extends AppController
{
	public function __construct()
	{
		parent::__construct();
        $this->loadModel('Picture');
	}

	public function homeAction()
	{
	    $this->app->setTitle('Accueil');

		$pictureEntity = $this->PictureEntity;
		$lastPictures = $pictureEntity->findLast(3);

        $this->render('homepage', compact('lastPictures'));
	}

}

?>