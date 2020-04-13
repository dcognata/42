<?php

namespace Camagru\Controller;

use \Core\Form\Form;
use \Core\Mail\Mailer;

class GalleryController extends AppController
{

	public function __construct()
	{
		parent::__construct();
		$this->loadModel('Picture');
        $this->loadModel('User');
        $this->loadModel('Like');
        $this->loadModel('Comment');
    }

    /*
     * */
    public function displayAction()
    {
        $this->app->setTitle('Galerie');

        $pictureEntity = $this->PictureEntity;
        $lastPictures = $pictureEntity->findOffset(6, 0);

        $this->render('gallery.display', compact('lastPictures'));
    }

    /*
     * */
    public function ajaxInfinityLoaderAction()
    {
        if ($this->app->is_ajax()) {
            $to = (6 * (int)$_POST['nbDisplay']);
            $pictureEntity = $this->PictureEntity;
            $lastPictures = $pictureEntity->findOffset(6, $to);
            echo json_encode($lastPictures);
        }
    }

    /*
     * */
    public function viewAction()
    {
        $_page_id = filter_var(htmlspecialchars($_GET['id']));
        $this->app->setTitle('Photo - ' . $_page_id);

        $pictureEntity = $this->PictureEntity;
        $pic = $pictureEntity->find($_page_id);
        if (!$pic)
            $this->notFound();

        $likeEntity = $this->LikeEntity;
        $like = $likeEntity->findByUserAndPicture($this->auth->getUserId(), $_page_id);
        $commentEntity = $this->CommentEntity;
        $comments = $commentEntity->findBy('picture_id', $_page_id);

        $form = new Form($_POST);
        $errorComment = null;
        $errorToken = null;
        if (!empty($_POST['submit']) && $_POST['submit'] == 'true') {
            $calc = hash_hmac('sha256', 'hashedForm', $_SESSION['token']);
            if (hash_equals($calc, $_POST['token'])) {
                $comment = filter_var(htmlspecialchars($_POST['comment']), FILTER_SANITIZE_STRING);

                if (empty($comment))
                    $errorComment = "Votre commentaire est vide.";
                else if (strlen($comment) <= 5)
                    $errorComment = "Votre commentaire est trop court (6 char min).";
                else if (!$errorComment) {
                    $commentEntity->create([
                        'comment' => $comment,
                        'user_id' => $this->auth->getUserId(),
                        'picture_id' => $_page_id,
                        'published_at' => date('Y-m-d H:i:s'),
                    ]);
                    $pictureEntity->update($_page_id, [
                        'comments' => $pic->comments + 1,
                    ]);
                    if ($_SESSION['mailable']) {
                        $url = 'http://' . $_SERVER['HTTP_HOST'];
                        $mail = new Mailer($_SESSION['mail'], 'Camagru Commentaire', "Un utilisateur a commenter votre photo.<br><br>Suivez ce lien :<br>$url"
                        );
                        $mail->sendMail();
                    }

                    header('Location: index.php?p=gallery.view&id='.$_page_id.'&msg=Le commentaire a bien ete poste.');
                }
            } else {
                $errorToken = true;
            }
        }

        $this->render('gallery.view', compact(
            'pic', 'like', 'comments',
            'form', 'comment', 'errorComment', 'errorToken'
        ));
    }

    /*
     * */
    public function likeAjaxAction()
    {
        if ($this->app->is_ajax() && $this->auth->logged() !== false) {

            $id = (int)$_POST['id'];

            $pictureEntity = $this->PictureEntity;
            $pic = $pictureEntity->find($id);
            $nbLikes = $pic->likes;
            $likeEntity = $this->LikeEntity;
            if (($like = $likeEntity->findByUserAndPicture($this->auth->getUserId(), $_POST['id'])))
            {
                $likeEntity->remove($like->id);
                $pictureEntity->update($pic->id, [
                    'likes' => $nbLikes - 1
                ]);
                echo json_encode('unlike');
            } else {
                $pictureEntity->update($pic->id, [
                    'likes' => $nbLikes + 1
                ]);
                $likeEntity->create([
                    'user_id' => $this->auth->getUserId(),
                    'picture_id' => $id,
                ]);
                echo json_encode('like');
            }
        } else {
            echo json_encode('Not logged');
        }
    }

	/*
	 * Delete Picture Action
	 * */
	public function deleteAction()
	{
	    $pictureId = filter_var(htmlspecialchars($_GET['id']));

        $pictureEntity = $this->PictureEntity;
        $picture = $pictureEntity->find($pictureId);
        if (!$picture) {
        	$this->notFound();
        } else {
            $path = "./public" . $picture->path;
            $pictureEntity->remove($pictureId);
            unlink($path);
            header('Location: index.php?p=gallery.display&msg=L\'image a bien ete supprimee.');
        }
    }
}