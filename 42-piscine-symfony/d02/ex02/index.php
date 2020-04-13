<?php

	include('HotBeverage.php');
	include('Tea.php');
	include('Coffee.php');
	include('TemplateEngine.php');

	$hb = new \HotBeverage();
	$c = new \Coffee();
	$t = new \Tea();

	$enginer = New \TemplateEngine('template.html');
	
	$hb->name = 'HotBeverage';
	$hb->price = 'price';
	$hb->resistence = 'resistence';
	$enginer->createFile($hb);

	$c->name = 'Coffee';
	$c->price = 'price';
	$c->resistence = 'resistence';
	$c->description = 'description';
	$c->comment = 'comment';
	$enginer->createFile($c);
	
	$t->name = 'Tea';
	$t->price = 'price';
	$t->resistence = 'resistence';
	$t->description = 'description';
	$t->comment = 'comment';
	$enginer->createFile($t);
?>