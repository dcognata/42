<?php

/**
* Template Engine
*/
class TemplateEngine
{
	function createFile($fileName, $templateName, $parameters) {
		if (file_exists($templateName)) {
			$contents = file_get_contents($templateName);
		}
		foreach ($parameters as $key => $value) {
			if (strpos($contents, '{'.$key.'}') !== false) {
			    $contents = str_replace('{'.$key.'}', $value, $contents);
			}
		}
		file_put_contents($fileName, $contents);
	}
}

?>