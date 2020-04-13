<?php

namespace ex05Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use ex05Bundle\Form\ex05Type;
use ex05Bundle\Entity\ex05;
use Symfony\Component\HttpFoundation\Request;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     */
    public function indexAction()
    {
        return $this->render('@ex05/Default/index.html.twig');
    }

    /**
     * @Route("/form")
     */
    public function formAction(Request $request)
    {
        $entityManager = $this->getDoctrine()->getManager();
        $user = new ex05();
        $form = $this->createForm(ex05Type::class, $user);

        $form->handleRequest($request);
	    if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->persist($user);
            $entityManager->flush();
			return $this->redirectToRoute('ex05_default_formsuccess');
	    }

        return $this->render('@ex05/Default/form.html.twig', array(
            'form' => $form->createView(),
        ));
    }

    /**
     * @Route("/formSuccess")
     */
    public function formSuccessAction()
    {
    	$entityManager = $this->getDoctrine()->getManager();
    	$users = $entityManager->getRepository('ex05Bundle:ex05')->findAll();

        return $this->render('@ex05/Default/success.html.twig', array(
        	'users' => $users,
        ));
    }

    /**
     * @Route("/delete/{id}")
     */
    public function deleteAction($id)
    {
        $entityManager = $this->getDoctrine()->getManager();
        $user = $entityManager->getRepository('ex05Bundle:ex05')->findOneById($id);


        if ($user) {
            $entityManager->remove($user);
            $entityManager->flush();
            $this->addFlash(
                'success',
                'Your changes were applyed!'
            );
        } else {
            $this->addFlash(
                'error',
                'Your changes were not applyed!'
            );
        }

        return $this->redirectToRoute('ex05_default_formsuccess');
    }
}