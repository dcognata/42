<?php

namespace E00Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Response;

class DefaultController extends Controller
{
    /**
     * @Route("/firstpage/")
     */
    public function indexAction()
    {
        return new Response(
            "Hello world!"
        );
    }
}
