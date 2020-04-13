<?php

namespace E02Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\ChoiceType;
use Symfony\Component\Validator\Constraints\NotBlank;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     */
    public function indexAction(Request $request)
    {
		$time = null;
        $message = null;

	    $form = $this->createFormBuilder()
	        ->add('message', TextType::class, array(
		        'label' => 'Message',
				'constraints' => array(
					new NotBlank(),
				),
		    ))
	        ->add('timestamp', ChoiceType::class, array(
		        'label' => 'Include timestamp',
		        'choices' => array(
		            'Yes' => true,
		            'No' => false,
		        ),
	        ))
	        ->getForm();

	    $form->handleRequest($request);

	    if ($form->isSubmitted() && $form->isValid()) {
	        $data = $form->getData();
			if ($data['timestamp'] == true)
				$time = time();
	        $message = $data['message'];

		    // parameter file / add in file
			if ($this->container->hasParameter('file_name'))
				$fileName = $this->container->getParameter('file_name');
			else
				$fileName = 'form_message.txt';

			$root = $this->container->getParameter('kernel.project_dir');


			file_put_contents($root . '/' . $fileName, $message . ' ' . $time . "\n", FILE_APPEND | LOCK_EX);
	    }

        return $this->render('@E02\Default\index.html.twig', array(
            'form' => $form->createView(),
			'time' => $time,
	        'message' => $message,
        ));
    }
}
