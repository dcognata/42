<?php

namespace ex02Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Form\Extension\Core\Type\TextType;
use Symfony\Component\Form\Extension\Core\Type\EmailType;
use Symfony\Component\Form\Extension\Core\Type\TextareaType;
use Symfony\Component\Form\Extension\Core\Type\DateTimeType;
use Symfony\Component\Form\Extension\Core\Type\CheckboxType;
use Symfony\Component\Form\Extension\Core\Type\SubmitType;
use Symfony\Component\Form\FormError;

class DefaultController extends Controller
{
	private $database_host;
	private $database_name;
	private $database_user;
	private $database_password;
	private $pdo;

	private function _getConnection()
	{
        $connection = new \PDO("mysql:host=".$this->database_host, $this->database_user, $this->database_password);

		$connection->query("CREATE DATABASE IF NOT EXISTS ".$this->database_name." CHARACTER SET utf8 COLLATE utf8_general_ci");
		$connection->query("use ".$this->database_name);

        return $connection;
    }

	private function _createTable($table)
	{
		$sql = "CREATE TABLE $table (
			    id int(11) AUTO_INCREMENT PRIMARY KEY,
			    username VARCHAR(255) UNIQUE,
			    name VARCHAR(255),
			    email VARCHAR(255) UNIQUE,
			    enable BOOLEAN,
		   	    birthdate DATETIME,
		   	    address LONGTEXT)";
	    $this->pdo->exec($sql);
    }

    private function _sendData($table, $data)
    {
    	if ($this->container->hasParameter('database_host'))
			$this->database_host = $this->container->getParameter('database_host');
    	if ($this->container->hasParameter('database_name'))
			$this->database_name = $this->container->getParameter('database_name');
    	if ($this->container->hasParameter('database_user'))
			$this->database_user = $this->container->getParameter('database_user');
    	if ($this->container->hasParameter('database_password'))
			$this->database_password = $this->container->getParameter('database_password');
		
		$sql = "INSERT INTO `$table` (`username`, `name`, `email`, `enable`, `birthdate`, `address`) VALUES (:username, :name, :email, :enable, :birthdate, :address)"; 

		$this->pdo = $this->_getConnection();
		$statement = $this->pdo->prepare($sql);
		 
		$statement->bindValue(':username', $data['username']);
		$statement->bindValue(':name', $data['name']);
		$statement->bindValue(':email', $data['email']);
		$statement->bindValue(':enable', $data['enable']);
		$statement->bindValue(':birthdate', ($data['birthdate']) ? $data['birthdate']->format('Y-m-d H:i:s') : null);
		$statement->bindValue(':address', $data['address']);
		 
		$inserted = $statement->execute();
    }

    private function _getOne($sql)
    {
    	if ($this->container->hasParameter('database_host'))
			$this->database_host = $this->container->getParameter('database_host');
    	if ($this->container->hasParameter('database_name'))
			$this->database_name = $this->container->getParameter('database_name');
    	if ($this->container->hasParameter('database_user'))
			$this->database_user = $this->container->getParameter('database_user');
    	if ($this->container->hasParameter('database_password'))
			$this->database_password = $this->container->getParameter('database_password');
		
		$this->pdo = $this->_getConnection();
		$statement = $this->pdo->prepare($sql);
		$statement->execute();

		return ($statement->fetch(\PDO::FETCH_ASSOC));
    }

    private function _getAll($sql)
    {
    	if ($this->container->hasParameter('database_host'))
			$this->database_host = $this->container->getParameter('database_host');
    	if ($this->container->hasParameter('database_name'))
			$this->database_name = $this->container->getParameter('database_name');
    	if ($this->container->hasParameter('database_user'))
			$this->database_user = $this->container->getParameter('database_user');
    	if ($this->container->hasParameter('database_password'))
			$this->database_password = $this->container->getParameter('database_password');
		
		$this->pdo = $this->_getConnection();
		$statement = $this->pdo->prepare($sql);
		$statement->execute();

		return ($statement->fetchAll(\PDO::FETCH_ASSOC));
    }

    /**
     * @Route("/")
     */
    public function indexAction()
    {
        return $this->render('@ex02/Default/index.html.twig');
    }

    /**
     * @Route("/form")
     */
    public function formAction(Request $request)
    {
	    $defaultData = array('message' => 'Type your message here');
	    $form = $this->createFormBuilder($defaultData)
	        ->add('username', TextType::class, array(
	        	'required' => false
	        ))
	        ->add('name', TextType::class, array(
	        	'required' => false
	        ))
	        ->add('email', EmailType::class, array(
	        	'required' => false
	        ))
	        ->add('enable', CheckboxType::class, array(
	        	'required' => false
	        ))
	        ->add('birthdate', DateTimeType::class, array(
	        	'required' => false
	        ))
	        ->add('address', TextareaType::class, array(
	        	'required' => false
	        ))
	        ->add('send', SubmitType::class)
	        ->getForm();

	    $form->handleRequest($request);

	    if ($form->isSubmitted() && $form->isValid()) {
	        $data = $form->getData();
	        $username = $data['username'];
	        $email = $data['email'];

	        $ret = $this->_getOne("SELECT username, email FROM ex02 WHERE `username` = '$username' OR `email` = '$email'");

	        if (!$ret) {
	        	$this->_sendData('ex02', $data);
    			return $this->redirectToRoute('ex02_default_formsuccess');
	        } else {
	        	if ($ret['username'] == $username)
	        		$form->get('username')->addError(new FormError('Cette valeur est deja utilisee'));
	        	if ($ret['email'] == $email)
	        		$form->get('email')->addError(new FormError('Cette valeur est deja utilisee'));
	        }

	    }

        return $this->render('@ex02/Default/form.html.twig', array(
            'form' => $form->createView(),
        ));
    }

    /**
     * @Route("/formSuccess")
     */
    public function formSuccessAction()
    {
        $users = $this->_getAll("SELECT * FROM ex02");

        return $this->render('@ex02/Default/success.html.twig', array(
        	'users' => $users,
        ));
    }

    /**
     * @Route("/createTable")
     */
    public function createTableAction()
    {
    	if ($this->container->hasParameter('database_host'))
			$this->database_host = $this->container->getParameter('database_host');
    	if ($this->container->hasParameter('database_name'))
			$this->database_name = $this->container->getParameter('database_name');
    	if ($this->container->hasParameter('database_user'))
			$this->database_user = $this->container->getParameter('database_user');
    	if ($this->container->hasParameter('database_password'))
			$this->database_password = $this->container->getParameter('database_password');

		$this->pdo = $this->_getConnection();
		$this->_createTable('ex02');

    	return $this->redirectToRoute('ex02_default_form');
    }
}
