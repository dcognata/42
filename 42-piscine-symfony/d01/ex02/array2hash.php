<?php 

function array2hash($array)
{
	$hashedArray = array();
	foreach ($array as $key => $subArray) {
		if (isset($subArray[0]) && isset($subArray[1])) {
			$hashedArray[$subArray[1]] = $subArray[0];
		}
	}

	return ($hashedArray);
}

?>