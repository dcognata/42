<?php

namespace Core\Repository;

/**
* 
*/
class Repository
{
    public function __get($key) {
        $method = 'get' . ucfirst($key);
        $this->$key = $this->$method();
        return $this->$key;
    }
}
