<?php

/**
* HotBeverage
*/
class HotBeverage
{
	public $name;
	public $price;
	public $resistence;

	public function getName() {
		return $this->name;
	}

	public function setName($value) {
		$this->name = $value;

		return $this;
	}

	public function getPrice() {
		return $this->price;
	}

	public function setPrice($value) {
		$this->price = $value;

		return $this;
	}

	public function getResistence() {
		return $this->resistence;
	}

	public function setResistence($value) {
		$this->resistence = $value;

		return $this;
	}

	public function __set($property, $value)  
	{
		if (property_exists($this, $property)) {  
			$this->$property = $value;  
		}
	}

	public function __get($property)  
	{
		if (property_exists($this, $property)) {  
			return $this->$property;  
		}
	}
}

?>