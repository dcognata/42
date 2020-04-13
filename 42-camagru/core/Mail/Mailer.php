<?php

namespace Core\Mail;

/**
* 
*/
class Mailer
{
	private $to;
	private $mail;
	private $subject;
	private $message;

	private $headers;

	function __construct($to = 'dcognata@student.42.fr', $subject, $message)
	{
		$this->to      = $to;
		$this->subject = '[CAMAGRU] - ' . $subject;
		$this->message = $message;
		$this->headers = "MIME-Version: 1.0" . "\r\n" . 
			"Content-type: text/html; charset=UTF-8" . "\r\n" .
			"From: Camagru <dcognata@student.42.fr>\r\n". 
    		"Reply-To: dcognata@student.42.fr" . "\r\n" . 
    		"X-Mailer: PHP/" . phpversion();
	}

	public function sendMail()
	{
		try {
			mail($this->to, $this->subject, $this->message, $this->headers);
		} catch (Exception $e) {
			var_dump($e);
			echo "Mail non envoyé : " . $e;
			return false;
		}
	}
}

?>