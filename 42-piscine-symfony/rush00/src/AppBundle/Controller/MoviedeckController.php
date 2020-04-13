<?php

namespace AppBundle\Controller;

use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;

use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;

use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Filesystem\Exception\IOExceptionInterface;
use aharen\OMDbAPI;

class MoviedeckController extends Controller
{
    /**
     * @Route("/deck", name="map_deck")
     */
	public function indexAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

		$movies = $this->get('session')->get('all_movies');

		$result = [];
		$omdb = new OMDbAPI('32dee48', false, false);
		foreach ($movies as $movie)
		{
			$result[] = $omdb->fetch('i', $movie);
		}
		return $this->render('@App/Map/deck.html.twig', [
			"curr_movies" => $this->get('session')->get('moviemons'),
			"all_movies" => $result
			]
		);
	}
}
