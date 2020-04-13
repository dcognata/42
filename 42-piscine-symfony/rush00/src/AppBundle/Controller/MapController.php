<?php

namespace AppBundle\Controller;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;

use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;

use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Filesystem\Exception\IOExceptionInterface;
use Symfony\Component\Finder\Finder;

class MapController extends Controller
{
    /**
     * @Route("/map", name="map_game")
     */
	public function indexAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

        return $this->render('@App/Map/map.html.twig');
	}

    /**
     * @Route("/map/case/{direction}", name="map_game_direct")
     */
	/*
	 *	left: 0
	 *	top: 1
	 *	right: 2
	 *	bottom: 3
	 */
	public function caseDirAction($direction)
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

        $pos = $this->get('session')->get('playerPos');
		switch ($direction)
		{
			case 0:
				if ($pos['x'] > 0)
					$pos['x'] -= 1;
			break;
			case 1:
				if ($pos['y'] > 0)
					$pos['y'] -= 1;
			break;
			case 2:
				if ($pos['x'] < 4)
					$pos['x'] += 1;
			break;
			case 3:
				if ($pos['y'] < 4)
					$pos['y'] += 1;
			break;

		}
        $this->get('session')->set('firstMove', false);
        $this->get('session')->set('playerPos', $pos);
        return $this->redirectToRoute('map_game_case');
	}

    /**
     * @Route("/map/case", name="map_game_case")
     */
	public function caseAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

        $pos = $this->get('session')->get('playerPos');
		return $this->render('@App/Map/case.html.twig', [
			"color" => $this->get('session')->get('map')[$pos['y']][$pos['x']]
		]);
	}
}
