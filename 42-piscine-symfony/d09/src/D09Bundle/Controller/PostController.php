<?php

namespace D09Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Session\Session;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\PasswordType;
use Symfony\Component\Validator\Constraints\NotBlank;
use Symfony\Component\HttpFoundation\Response;

class PostController extends Controller
{
    /**
     * @Route("/postForm", name="post_form")
     */
	public function monAjaxControllerAction()
	{
	    $htmlToRender = $this->renderView('@D09/Post/index.html.twig', array(
	    	
		));
	     
	    return new Response($htmlToRender);
	}

    /**
     * @Route("/post", name="post")
     */
	public function defaultAction(Request $request)
	{
		if ($this->getUser() && $this->get('security.authorization_checker')->isGranted('ROLE_USER')) {
			$logged = true;
		} else {
			$logged = false;
		}


        return $this->render('@D09/Post/index.html.twig', array(
        	'logged' => $logged,
		));
	}
}