<?php
$file = 'ex01.txt';

if (file_exists($file)) {
    $content = file_get_contents($file);
    $content = explode(',', $content);
    foreach ($content as $key => $value) {
    	echo "$value\n";
    }
    exit;
}
?>