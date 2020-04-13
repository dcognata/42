<?php

/**
* Template Engine
*/
class TemplateEngine
{
	private $templateName;
	private $fileName;

	function __construct($templateName)
	{
		$this->templateName = $templateName;
	}

	function createFile(HotBeverage $text)
	{
		$oReflectionClass = new ReflectionClass($text);
		$this->fileName = $oReflectionClass->getName();

		if (file_exists($this->templateName)) {
			$contents = file_get_contents($this->templateName);
		}

		$parameters = array();
		preg_match_all('/{.*?}/', $contents, $parameters);
		$parameters = $parameters[0];

		foreach ($parameters as $value) {
			switch ($value) {
				case '{nom}':
					$v = 'name';
					break;
				case '{prix}':
					$v = 'price';
					break;
				case '{resistance}':
					$v = 'resistence';
					break;
				case '{description}':
					$v = 'description';
					break;
				case '{commentaire}':
					$v = 'comment';
					break;
				default:
					break;
			}

		    $contents = str_replace($value, $text->$v, $contents);
		}
		file_put_contents($this->fileName, $contents);
	}
}

?>