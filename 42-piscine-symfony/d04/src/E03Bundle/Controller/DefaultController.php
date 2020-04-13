<?php

namespace E03Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     */
    public function indexAction()
    {
    	// $black = ;
    	// $red = ;
    	// $blue = ;
    	// $green = ;
    	// rgb(0, 255, 0)



	    // parameter file / add in file
		if ($this->container->hasParameter('e03.number_of_colors'))
			$nbColors = $this->container->getParameter('e03.number_of_colors');
		else 
			$nbColors = 24;

		$colors = [
			[[0, 0, 0], [255, 0, 0], [0, 0, 255], [0, 255, 0]]
		];

		$toAdd = number_format(round(255 / $nbColors), 0);
		$i = 1;
		while ($i < $nbColors)
		{
			$colors[] = [
				[
					$colors[$i - 1][0][0] + $toAdd,
					$colors[$i - 1][0][1] + $toAdd,
					$colors[$i - 1][0][2] + $toAdd,
				],
				[
					255,
					$colors[$i - 1][1][1] + $toAdd,
					$colors[$i - 1][1][2] + $toAdd,
				],
				[
					$colors[$i - 1][2][0] + $toAdd,
					$colors[$i - 1][2][1] + $toAdd,
					255
				],
				[
					$colors[$i - 1][3][0] + $toAdd,
					255,
					$colors[$i - 1][3][2] + $toAdd,
				]
			];
			$i++;
		}

        return $this->render('@E03\Default\index.html.twig', array(
        	'colors' => $colors,
        	'nbColors' => $nbColors,
        ));
    }
}
