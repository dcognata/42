<?php

namespace D07Bundle\Twig;

use D07Bundle\Service\Ex03Service;

class Ex03Extension extends \Twig_Extension
{
    public function getFilters()
    {
        return array(
            new \Twig_SimpleFilter('uppercaseWords', array($this, 'uppercaseWords')),
            new \Twig_SimpleFilter('countNumbers', array($this, 'countNumbers')),
        );
    }

    public function uppercaseWords($str)
    {
        return Ex03Service::getUppercaseWords($str);
    }

    public function countNumbers($str)
    {
    	return Ex03Service::getCountNumbers($str);
    }
}