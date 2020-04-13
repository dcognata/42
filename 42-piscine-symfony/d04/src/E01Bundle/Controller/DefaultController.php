<?php

namespace E01Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     */
    public function indexAction()
    {
    	$categories = array(
    		'controller',
			'routing', 
			'templating', 
			'doctrine',
			'testing', 
			'validation', 
			'forms', 
			'security', 
			'cache', 
			'translations', 
			'services'
    	);

        return $this->render('@E01/Default/index.html.twig', array(
        	'categories' => $categories,
        ));
    }

    /**
     * @Route("/{category}/")
     */
    public function pageAction($category)
    {
    	$categories = array(
    		'controller' => 'controller',
			'routing' => 'routing', 
			'templating' => 'templating', 
			'doctrine' => 'doctrine',
			'testing' => 'testing', 
			'validation' => 'validation', 
			'forms' => 'forms', 
			'security' => 'security', 
			'cache' => 'cache', 
			'translations' => 'translations', 
			'services' => 'services',
    	);

    	if (!array_key_exists($category, $categories))
		    return $this->redirectToRoute('e01_default_index');

        return $this->render('@E01/Default/_'.$category.'.html.twig');
    }
}
