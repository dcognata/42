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

class OptionsController extends Controller
{
    /**
     * @Route("/", name="homepage")
     */
	public function indexAction()
	{
		$dir    = $this->get('kernel')->getProjectDir() . "/saves/";
		$files = array_diff(scandir($dir), array('..', '.', '.gitkeep'));

	    $breadcrumbs = $this->get("white_october_breadcrumbs");
	    $breadcrumbs->addItem("Accueil", $this->get("router")->generate("homepage"));

        return $this->render('@App/Default/index.html.twig', [
        	'sessions' => $files,
        ]);
	}

    /**
     * @Route("/new", name="new_game")
     */
	public function newAction(Request $request)
	{
		$this->get('session')->remove('curr_movie');
		$form = $this->createFormBuilder()
		->add('name', TextType::class, [
			'label' => 'Nom',
			'required' => true,
		])
		->add('send', SubmitType::class, [
			'attr' => [
				'class' => 'btn btn-info'
			],
			'label' => 'Jouer',
		])
		->getForm();

		$form->handleRequest($request);
		if ($form->isSubmitted() && $form->isValid()) {
			$data = $form->getData();

			$this->get('session')->remove('moviemons');
			$fs = new Filesystem();
			$file = $this->get('kernel')->getProjectDir() . "/saves/" . $data['name'];
			if ($fs->exists($file) == true)
			{
        		return $this->redirectToRoute('homepage');
			}

			$movies = $this->getMovies();
			$map = [
				['#FFFFFF','#F0F8FF','#FDF5E6','#FFF0F5','#008080'],
				['#F0FFF0','#F8F8FF','#FFFAF0','#FFE4E1','#87CEEB'],
				['#FFFAFA','#F5F5F5','#FFFFF0','#40E0D0','#FFC0CB'],
				['#F5FFFA','#FFF5EE','#FAEBD7','#87CEFA','#002200'],
				['#F0FFFF','#F5F5DC','#FAF0E6','#C71585','#ADD8E6']
			];
			$cities = [
				['Aearyl','Bergan','Tasaid','Mithe','Guotemair'],
				['Faret','Argon','Simmer','Lyvred','Kaladh'],
				['Gavynnar','Druid','Arius','Gimma','Keevarioll'],
				['Caomhaim','Dvnock','Mulus','Thomli','Godusk'],
				['Cripton','Elatio','Odely','Lawnie','Kerry']
			];
			
			// dump($movies);
			// dump($map);
			// $omdb->fetch('i', 'tt0338013');
			// exit();

			$this->get('session')->set('playerName', $data['name']);
			$this->get('session')->set('map', $map);
			$this->get('session')->set('cities', $cities);
            $this->get('session')->set('playerPos', ['x' => 2, 'y' => 2]);
			$this->get('session')->set('all_movies', $movies);
			$this->get('session')->set('player_life', 5);
			$this->get('session')->set('firstMove', true) ; // [id1, id2, ...]

  			return $this->redirectToRoute('map_game_case');
		}
		
        return $this->render('@App/Default/new.html.twig', [
			"form" => $form->createView(),
		]);
	}

    /**
     * @Route("/save", name="save_game")
     */
	public function saveAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

		$infos = [];
		$infos["name"] = $this->get('session')->get('playerName');
		$infos["pos"] = $this->get('session')->get('playerPos'); // ['x' => x, 'y' => n]
		$infos["moviemons"] = $this->get('session')->get('moviemons'); // [id1, id2, ...]
		$infos["pv"] = $this->get('session')->get('player_life'); // [id1, id2, ...]
		$infos["firstMove"] = $this->get('session')->get('firstMove'); // [id1, id2, ...]

		$fs = new Filesystem();

		$file = $this->get('kernel')->getProjectDir() . "/saves/" . $infos['name'];
		if ($fs->exists($file) == false)
			$fs->touch($file);

		$fs->dumpFile($file, json_encode($infos));
		// redirect -> map coordonnees
		return $this->redirectToRoute('map_game_case');
	}

    /**
     * @Route("/{name}/load", name="load_game")
     */
	public function loadAction(Request $request, $name)
	{
		$this->get('session')->remove('curr_movie');
		$fs = new Filesystem();

		$file = $this->get('kernel')->getProjectDir() . "/saves/" . $name;
		if ($fs->exists($file) == false)
		{
        	return $this->render('@App/Default/index.html.twig', [
				"error" => "This player does not exist."
			]);
		}
		$content = file_get_contents($file);
		$json = json_decode($content, true);

		$this->get('session')->set('playerName', $json['name']);
		$this->get('session')->set('playerPos', $json['pos']); // ['x' => x, 'y' => n]
		$this->get('session')->set('moviemons', $json['moviemons']); // [id1, id2, ...]
		$this->get('session')->set('player_life', $json['pv']) ; // [id1, id2, ...]
		$this->get('session')->set('firstMove', $json['firstMove']) ; // [id1, id2, ...]
		$this->get('session')->set('all_movies', $this->getMovies());
		// redirect -> map coordonnees
		return $this->redirectToRoute('map_game_case');
	}

    /**
     * @Route("/cancel", name="cancel_game")
     */
	public function cancelAction()
	{
		if ($this->get('session')->get('playerName') == null)
			return $this->redirectToRoute('homepage');

		$this->get('session')->set('player_life', 5);
		$this->get('session')->set('firstMove', true);
		$this->get('session')->remove('curr_movie');
		return $this->redirectToRoute('map_game_case');
	}

	private function getMovies()
	{
		$movies = [];

		$omdb = new OMDbAPI('32dee48', false, false);
		$res = $omdb->search('Wonder');

		foreach ($res->data->Search as $key => $value) {
			$movies[] = $value->imdbID;
		}
	
		return $movies;
	}

}
