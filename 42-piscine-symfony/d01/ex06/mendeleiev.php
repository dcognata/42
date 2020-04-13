<?php 

//SET TEMPLATE
$head = 
"<!DOCTYPE html>
<html>
<head>
	<title>Mendelcuck</title>
</head>
<body>
	<table>
		<tr>";
$footer = "
	</table>
</body>
</html>";

//GET CONTENT
function getFileContent($file) {
	if (file_exists($file)) {
	    $content = file_get_contents($file);
	    $content = explode("\n", $content);
	    return $content;
	}
}
$array = getFilecontent('ex06.txt');

if ($array != null)
{

	//FORMAT ARRAY WITH REF
	function createRefArray($array) {
		$arr = array();

		foreach ($array as $key => $value) {
			$exploded = explode(',', $value);
			$subExploded = array();
			if (count($exploded) == 5) {
				$subExploded = explode('=', $exploded[0]);
				$n = explode(' ', str_replace('electron:', '', trim($exploded[4])));
				$r = 0;
				foreach ($n as $key => $nn) {
					$r += $nn;
				}
				$arr[] = array(
					'name' => trim($subExploded[0]),
					'position' => str_replace('position:', '', trim($subExploded[1])) + 1,
					'number' => str_replace('number:', '', trim($exploded[1])),
					'small' => str_replace('small: ', '', trim($exploded[2])),
					'molar' => str_replace('molar:', '', trim($exploded[3])),
					'electron' => $r,
				);
			}

		}
		return $arr;
	}
	$arrayRef = createRefArray($array);

	//CREATE HTML
	function getHTMLContent($arrayRef) {
		$body = "";
		$prev = 1;
		foreach ($arrayRef as $key => $value) {
				if ($value['position'] > $prev + 1) {
					$prev++;
					while ($prev < $value['position']) {
						$body .= "
							<td style=\"border: 1px solid black; padding:10px\">
							</td>";
						$prev++;
					}
						$body .= "
							<td style=\"border: 1px solid black; padding:10px\">
								<h4>".$value['name']."</h4>
								<ul>
									<li>No ".$value['number']."</li>
									<li>".$value['small']."</li>
									<li> ".$value['molar']." </li>
									<li>".$value['electron']." electron</li>
								</ul>
							</td>";
				} else {
					$body .= "
						<td style=\"border: 1px solid black; padding:10px\">
							<h4>".$value['name']."</h4>
							<ul>
								<li>No ".$value['number']."</li>
								<li>".$value['small']."</li>
								<li> ".$value['molar']." </li>
								<li>".$value['electron']." electron</li>
							</ul>
						</td>";
				}


				if ($value['position'] == 18) {
					$body .= "
					</tr>
					<tr>";
					$prev = 1;
				} else {
					$prev = $value['position'];
				}
		}

		return $body;
	}
	$contents = $head . getHTMLContent($arrayRef) . $footer;

	// CREATE FILE
	file_put_contents("mendeleiev.html", $contents);
} else {
	$contents = $head . $footer;
	file_put_contents("mendeleiev.html", $contents);
}
?>








