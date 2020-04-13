<?php 

function search_by_states($str)
{
	$array = explode(',', $str);
	foreach ($array as $key => $value) {
		$array[$key] = trim($value);
	}

	$states = [
		'Oregon' => 'OR',
		'Alabama' => 'AL',
		'New Jersey' => 'NJ',
		'Colorado' => 'CO',
	];
	$capitals = [
		'OR' => 'Salem',
		'AL' => 'Montgomery',
		'NJ' => 'trenton',
		'KS' => 'Topeka',
	];

	foreach ($array as $key => $value) {
		$find = false;
		if (isset($states[$value]) && isset($capitals[$states[$value]])) {
			echo $capitals[$states[$value]] . " is the capital of $value.\n";
		} else {
			foreach ($capitals as $ke => $val) {
				if ($value == $val) {
					$isCapital = $ke;
					foreach ($states as $k => $v) {
						if ($isCapital == $v) {
							$isCapital = $k;
							$find = true;
							break ;
						}
					}
					break ;
				} else {
					$isCapital = false;
				}
			}
			if ($find) {
				echo $value . " is the capital of " . $isCapital . ".\n";
			} else {
				echo "$value is neither a capital nor a state.\n";
			}
		}
	}
}

search_by_states("Oregon, trenton, Topeka, NewJersey");

?>