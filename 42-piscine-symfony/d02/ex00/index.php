<?php

	include('TemplateEngine.php');

	$parameters = array(
		'nom' => 'Damien',
		'auteur' => 'dcognata',
		'description' => 'Roman d\'anticipation',
		'prix' => '6'
	);

	$enginer = new \TemplateEngine();
	$enginer->createFile('render.html', 'book_description.html', $parameters);

?>