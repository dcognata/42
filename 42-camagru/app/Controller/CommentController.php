<?php

namespace Camagru\Controller;

class CommentController extends AppController
{

	public function __construct()
	{
		parent::__construct();
		$this->loadModel('Comment');
		$this->loadModel('Picture');
	}

	/*
	 * */
	public function deleteAction()
	{
        if (!$this->auth->logged())
            $this->app->forbidden();

	    $commentId = filter_var(htmlspecialchars($_GET['id']));

        $commentEntity = $this->CommentEntity;
        $comment = $commentEntity->find($commentId);
        if (!$comment) {
            $this->notFound();
        } else {
            if ($comment->user_id != $this->auth->getUserId()) {
                $this->app->forbidden();
            }
	        $pictureEntity = $this->PictureEntity;
	        $picture = $pictureEntity->find($comment->picture_id);
	        if (!$comment) {
            	$this->notFound();
	        } else {
	        	$commentEntity->remove($commentId);
	        	$pictureEntity->update($picture->id, [
	        		'comments' => $picture->comments - 1,
	        	]);
	            header('Location: index.php?p=gallery.view&id='.$picture->id.'&msg=Le commentaire a bien ete supprime.');
	        }
        }
	}
}

?>