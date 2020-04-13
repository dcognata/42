<?php

namespace ex07Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use ex07Bundle\Form\ex07Type;
use ex07Bundle\Entity\ex07;
use Symfony\Component\HttpFoundation\Request;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     */
    public function indexAction()
    {
        return $this->render('@ex07/Default/index.html.twig');
    }

    /**
     * @Route("/form")
     */
    public function formAction(Request $request)
    {
        $entityManager = $this->getDoctrine()->getManager();
        $user = new ex07();
        $form = $this->createForm(ex07Type::class, $user);

        $form->handleRequest($request);
	    if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->persist($user);
            $entityManager->flush();
            $this->addFlash(
                'success',
                'Your changes were applyed!'
            );
			return $this->redirectToRoute('ex07_default_formsuccess');
	    }

        return $this->render('@ex07/Default/form.html.twig', array(
            'form' => $form->createView(),
        ));
    }

    /**
     * @Route("/edit/{id}")
     */
    public function editAction($id, Request $request)
    {
        $entityManager = $this->getDoctrine()->getManager();
        $user = $entityManager->getRepository('ex07Bundle:ex07')->findOneById($id);
        $form = $this->createForm(ex07Type::class, $user);

        $form->handleRequest($request);
        if ($form->isSubmitted() && $form->isValid()) {
            $entityManager->flush();
            $this->addFlash(
                'success',
                'Your changes were applyed!'
            );
            return $this->redirectToRoute('ex07_default_formsuccess');
        }

        return $this->render('@ex07/Default/form.html.twig', array(
            'form' => $form->createView(),
        ));
    }

    /**
     * @Route("/formSuccess")
     */
    public function formSuccessAction()
    {
    	$entityManager = $this->getDoctrine()->getManager();
    	$users = $entityManager->getRepository('ex07Bundle:ex07')->findAll();

        return $this->render('@ex07/Default/success.html.twig', array(
        	'users' => $users,
        ));
    }

    /**
     * @Route("/delete/{id}")
     */
    public function deleteAction($id)
    {
        $entityManager = $this->getDoctrine()->getManager();
        $user = $entityManager->getRepository('ex07Bundle:ex07')->findOneById($id);


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

        return $this->redirectToRoute('ex07_default_formsuccess');
    }
}