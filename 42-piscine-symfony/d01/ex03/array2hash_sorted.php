<?php 

function array2hash_sorted($array)
{
	$hashedArray = array();
	usort($array, function ($item1, $item2) {
	    if ($item1[0] == $item2[0]) return 0;
	    return $item1[0] > $item2[0] ? -1 : 1;
	});
	foreach ($array as $key => $subArray) {
		if (isset($subArray[0]) && isset($subArray[1])) {
			$hashedArray[$subArray[0]] = $subArray[1];
		}
	}

	return ($hashedArray);
}

?>