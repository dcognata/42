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
use aharen\OMDbAPI;

class GameController extends Controller
{
    /**
     * @Route("/map/fight", name="map_game_fight")
     */
	public function fightAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

		$omdb = new OMDbAPI('32dee48', false, false);
		$movie = $omdb->fetch('i', strval($this->get('session')->get('all_movies')[random_int(0, 9)]));

		if ($movie == null)
			$this->redirect('homepage');

		if (!$this->get('session')->get('curr_movie'))
		{
			$movie_stats = [];
		
			$movie_stats['id'] = $movie->data->imdbID;
			$movie_stats['name'] = $movie->data->Title;
			$movie_stats['img'] = $movie->data->Poster;
			$movie_stats['title'] = $movie->data->Title;
			$movie_stats['atq'] = random_int(1, 3);
			$movie_stats['esq'] = random_int(1, 90);
			$movie_stats['pv'] = random_int(1, 5);

			$this->get('session')->set('curr_movie', $movie_stats);
		}
		return $this->render('@App/Map/fight.html.twig',
			[
				'movie' => $this->get('session')->get('curr_movie'),
				'player_life' => $this->get('session')->get('player_life')
			]
		);
	}


    /**
     * @Route("/atq", name="game_atq")
     */
	public function attackAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

		$movie = $this->get('session')->get('curr_movie');
		if (random_int(1, 100) >= $movie['esq'])
		{
			$movie['pv'] -= 1;
			if ($movie['pv'] <= 0)
			{
				$tmp = $this->get('session')->get('moviemons');
				if (!$tmp)
					$tmp = [];
				array_push($tmp, $this->get('session')->get('curr_movie'));
				$tmp = $this->get('session')->set('moviemons', $tmp);
				$this->get('session')->remove('curr_movie');
				if (count($tmp) == 10)
					return $this->redirectToRoute('map_game_win');
				$this->get('session')->set('firstMove', true);
				return $this->redirectToRoute('map_game_case');
			}
			$this->get('session')->set('curr_movie', $movie);
		}
		else
		{
			$this->get('session')->set('player_life', $this->get('session')->get('player_life') - $movie['atq']);
			if ($this->get('session')->get('player_life') <= 0)
				return $this->redirectToRoute('map_game_over');

		}
		return $this->redirectToRoute("map_game_fight");
	}
    /**
     * @Route("/map/win", name="map_game_win")
     */
	public function winAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

		$name = $this->get('session')->remove('playerName');

		$this->get('session')->remove('playerName');
		$this->get('session')->remove('map');
        $this->get('session')->remove('playerPos');
		$this->get('session')->remove('all_movies');
		$this->get('session')->remove('moviemons');
		$this->get('session')->remove('curr_movie');
		$this->get('session')->remove('player_life');
        return $this->render('@App/Default/win.html.twig');
	}

    /**
     * @Route("/map/gameover", name="map_game_over")
     */
	public function gameOverAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

		$name = $this->get('session')->remove('playerName');

		$this->get('session')->remove('playerName');
		$this->get('session')->remove('map');
        $this->get('session')->remove('playerPos');
		$this->get('session')->remove('all_movies');
		$this->get('session')->remove('moviemons');
		$this->get('session')->remove('curr_movie');
		$this->get('session')->remove('player_life');
			
		$this->get('session')->remove('curr_movie');
        return $this->render('@App/Default/gameover.html.twig');
	}
}
