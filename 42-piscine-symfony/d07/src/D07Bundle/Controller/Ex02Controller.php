<?php

namespace D07Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Response;

class Ex02Controller extends Controller
{
    /**
     * @Route("/{_locale}/ex02/{count}", defaults={"_locale"="fr"}, requirements={
     *     "_locale"="en|fr",
     *	   "count"="0|1|2|3|4|5|6|7|8|9"
     * })
     */
    public function translationsAction($_locale, $count = 0)
    {
    	if ($this->container->hasParameter('d07.number'))
			$number = $this->container->getParameter('d07.number');

        return $this->render('@D07/ex02/ex02.html.twig', array(
        	'number' => $number,
        	'count'  => $count,
        ));
    }
}
