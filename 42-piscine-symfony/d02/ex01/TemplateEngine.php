<?php

/**
* Template Engine
*/
class TemplateEngine
{
	function createFile($fileName, Text $text) {
		$top =
"<!DOCTYPE html>
<html>
	<head>
		<title>{nom}</title>
	</head>
	<body>
		<h1>{nom}</h1>
		<p>
			Auteur: <b>{auteur}</b><br />
			Description: {description}<br />
			Prix: <b>{prix} &euro;</b>
		</p>
"
		;

		ob_start();
		$text->printStrings();
		$body = ob_get_contents();
		ob_end_clean();

		$bottom =
"	</body>
</html>"
		;

		file_put_contents($fileName, $top . $body . $bottom);
	}
}

?>