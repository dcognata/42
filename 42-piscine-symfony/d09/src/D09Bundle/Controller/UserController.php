<?php

namespace D09Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\JsonResponse;

class UserController extends Controller
{
    /**
     * @Route("/login", name="login")
     */
	public function loginAction(Request $request)
	{
		$user = $this->container->getParameter('user');
		$password = $this->container->getParameter('password');

		if ( $request->isXmlHttpRequest() ) {
			if ($request->request->get('username') != "" && $request->request->get('password') != "" &&
				$user == $request->request->get('username') && $password == $request->request->get('password')) {
				$response = new JsonResponse();
		        $response->setStatusCode(200);
		        return $response;
		    } else {
				$response = new JsonResponse();
				$response->setStatusCode(201);
				$response->setData(array('errorMessage' => 'Connexion impossible : Verifiez vos informations'));
				return $response;
	        }
		}

        return $this->render('@D09/User/login.html.twig');
    }

    /**
     * @Route("/login_check", name="login_check")
     */
	public function loginCheckAction(Request $request)
	{
		$response = new JsonResponse();
        $response->setStatusCode(200);
        return $response;
	}
}