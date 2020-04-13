<?php

namespace D07Bundle\Service;

class Ex03Service
{
    public function getUppercaseWords($str)
    {
        return ucwords($str);
    }

    public function getCountNumbers($str)
    {
    	return preg_match_all("/[0-9]/", $str);
    }
}