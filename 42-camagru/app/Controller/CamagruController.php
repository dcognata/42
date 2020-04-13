<?php

namespace Camagru\Controller;

use \Core\Form\Form;
use \Core\Mail\Mailer;

/**
* 
*/
class CamagruController extends AppController
{

	public function __construct()
	{
		parent::__construct();
		$this->loadModel('Picture');
	}

	public function shootAction()
	{
		$this->app->setTitle('Studio');

		if (!$this->auth->logged()) {
            header('HTTP/1.0 403 Forbidden');
            header('Location: index.php?p=security.login&msg=L\'accès à cet espace est réservé.');
        }

        $pictureEntity = $this->PictureEntity;
        $myPictures = $pictureEntity->findByUser($this->auth->getUserId());

		$this->render('camagru.shoot', compact('myPictures'));
	}

    /*
     * Delete Picture Action
     * */
    public function deleteAction()
    {
        if (!$this->auth->logged())
            $this->app->forbidden();

        $path = filter_var(htmlspecialchars($_GET['path']));

        if ($path) {
            $path = str_replace('public', '', $path);
            $pictureEntity = $this->PictureEntity;
            $picture = $pictureEntity->findOneBy('path', $path);
            if (!$picture) {
                $this->notFound();
            } else if ($picture->user_id != $this->auth->getUserId()) {
                $this->app->forbidden();
            } else {
                $path = $picture->path;
                $pictureEntity->remove($picture->id);
                unlink($path);
                header('Location: index.php?p=camagru.shoot&msg=L\'image a bien ete supprimee.');
            }
        } else {
            header('Location: index.php?p=gallery.display&msg=L\'image n\'existe pas.');
        }
    }

	private function imageCreateFromFile($filename)
	{
	    if (!file_exists($filename)) {
	        throw new InvalidArgumentException('File "'.$filename.'" not found.');
	    }
	    switch ( strtolower( pathinfo( $filename, PATHINFO_EXTENSION ))) {
	        case 'jpeg':
	        case 'jpg':
	            return imagecreatefromjpeg($filename);
	        break;

	        case 'png':
	            return imagecreatefrompng($filename);
	        break;

	        case 'gif':
	            return imagecreatefromgif($filename);
	        break;

	        default:
	            throw new InvalidArgumentException('File "'.$filename.'" is not valid jpg, png or gif image.');
	        break;
	    }
	}

	public function shootSaveAction()
	{
		if (!$this->auth->logged())
			$this->app->forbidden();

		if (isset($_POST['img']))
		{

			$name = '/uploads/' . $this->auth->getUserId() . '-' . time() . '.png';

			$img = $_POST['img'];
			$id = (empty($_POST['id'] || $_POST['id'] == "") ? 1 : $_POST['id'] );
            $img = str_replace('data:image/png;base64,', '', $img);
            $img = str_replace('data:image/jpeg;base64,', '', $img);
            $img = str_replace('data:image/jpg;base64,', '', $img);
			$img = str_replace(' ', '+', $img);
			$data = base64_decode($img);
			$file = ROOT . 'public' . $name;

			$width = 720;
            $height = 540;

			$im = imagecreatefromstring($data);
			$im2 = $this->imageCreateFromFile(ROOT . 'public/images/'. $id .'.png');
            $im = imagescale($im, $width, $height);

			imagecopyresized($im, $im2, 0, 0, 0, 0, $width, $height, $width, $height);

			$success = imagepng($im, $file);

	    	$pictureEntity = $this->PictureEntity;
			$pictureEntity->create([
	            'path' => $name,
	            'user_id' => $this->auth->getUserId(),
	        ]);

			echo 'public' . $name;
		}
		else
		{
			echo "erreur";
		}
	}
}

?>