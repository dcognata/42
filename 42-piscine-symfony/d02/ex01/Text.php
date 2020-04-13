 
<?php

/**
* Text Engine
*/
class Text
{
	public $strings;
	
	function __construct($strings = array())
	{
		$this->strings = $strings;
	}

	function addString($str)
	{
		$this->strings[] = $str;
	}

	function printStrings()
	{
		foreach ($this->strings as $key => $value) {
			echo "\t\t<p>$value</p>\n";
		}
	}

}
?>