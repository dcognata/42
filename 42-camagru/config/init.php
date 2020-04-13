<?php

define('ROOT', __DIR__ . '/../');
define('PATH', $_SERVER['REQUEST_URI']);

function exception_handler($exception) {
  echo "Exception non attrapée :<br>" , $exception->getMessage(), "<br>";
}

set_exception_handler('exception_handler');

?>
