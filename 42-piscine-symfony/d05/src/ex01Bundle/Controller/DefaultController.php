<?php

namespace ex01Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Console\Application;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\Console\Input\ArrayInput;
use Symfony\Component\Console\Output\BufferedOutput;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpKernel\KernelInterface;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;

class DefaultController extends Controller
{
    /**
     * @Route("/generate")
     */
    public function generateAction()
    {
        $kernel = $this->get('kernel');
        $application = new Application($kernel);
        $application->setAutoExit(false);

        $input = new ArrayInput(array(
           'command' => 'doctrine:schema:update',
           '--force' => true,
        ));

        $output = new BufferedOutput();
        $application->run($input, $output);

        $content = $output->fetch();

        $this->addFlash(
            'success',
            'Table created'
        );

        return $this->render('@ex01/Default/index.html.twig', array(
            'txt' => $content,
        ));
    }

    /**
     * @Route("/")
     */
    public function indexAction()
    {
        return $this->render('@ex01/Default/index.html.twig');
    }
}
