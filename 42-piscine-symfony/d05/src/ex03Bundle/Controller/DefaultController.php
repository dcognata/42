<?php

namespace ex03Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use ex03Bundle\Form\ex03Type;
use ex03Bundle\Entity\ex03;
use Symfony\Component\HttpFoundation\Request;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     */
    public function indexAction()
    {
        return $this->render('@ex03/Default/index.html.twig');
    }

    /**
     * @Route("/form")
     */
    public function formAction(Request $request)
    {
        $entityManager = $this->getDoctrine()->getManager();
        $user = new ex03();
        $form = $this->createForm(ex03Type::class, $user);

        $form->handleRequest($request);
	    if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->persist($user);
            $entityManager->flush();
			return $this->redirectToRoute('ex03_default_formsuccess');
	    }

        return $this->render('@ex03/Default/form.html.twig', array(
            'form' => $form->createView(),
        ));
    }

    /**
     * @Route("/formSuccess")
     */
    public function formSuccessAction()
    {
    	$entityManager = $this->getDoctrine()->getManager();
    	$users = $entityManager->getRepository('ex03Bundle:ex03')->findAll();

        return $this->render('@ex03/Default/success.html.twig', array(
        	'users' => $users,
        ));
    }
}