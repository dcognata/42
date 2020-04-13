<?php

/**
* Tea
*/
class Tea extends HotBeverage
{
	public $description;
	public $comment;

	public function getDescription() {
		return $this->description;
	}

	public function setDescription($value) {
		$this->description = $value;

		return $this;
	}

	public function getComment() {
		return $this->comment;
	}

	public function setComment($value) {
		$this->comment = $value;

		return $this;
	}
}

?>

