<?php

namespace D07Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Response;

class Ex01Controller extends Controller
{
    /**
     * @Route("/ex01/")
     */
    public function ex01Action()
    {
    	if ($this->container->hasParameter('d07.number'))
			$number = $this->container->getParameter('d07.number');

        return new Response($number);
    }
}
