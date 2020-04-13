<?php

	include('Text.php');
	include('TemplateEngine.php');

	$strings = array(
		'Phrase 1 - array',
		'Phrase 2 - array',
		'Phrase 3 - array',
	);

	$text = new \Text(array('Phrase -1 - instanciation', 'Phrase 0 - instanciation'));
	foreach ($strings as $key => $value) {
		$text->addString($value);
	}

	$enginer = new \TemplateEngine();
	$enginer->createFile('render.html', $text);

?>