<?php

namespace Core\Form;

/**
* 
*/
class Form
{
	private $data;

	function __construct($data = array())
	{
		$this->data = $data;
	}

	protected function getValue($index)
	{
		if (is_object($this->data))
			return $this->data->$index;
		return isset($this->data[$index]) ? htmlspecialchars($this->data[$index], ENT_QUOTES) : null;
	}

	protected function getControlClass($icon)
	{
		$controlClass = (!empty($icon)) ? "control has-icons-left" : "control";
		if (!empty($error) || !empty($success))
			$controlClass .= " has-icons-right";
		return $controlClass;
	}

	protected function getInputClass($error, $success)
	{
		$inputclass = "input";
		if (!empty($error))
			$inputclass .= " is-danger";
		else if (!empty($success))
			$inputclass .= " is-success";

		return $inputclass;
	}

	protected function getMessageFlash($error = null, $success = null)
	{
		if (!empty($error))
			return "<span class=\"icon is-small is-right\"><i class=\"fa fa-warning\"></i></span><p class=\"help is-danger\">". $error ."</p>";
		else if (!empty($success))
			return "<span class=\"icon is-small is-right\"><i class=\"fa fa-check\"></i></span><p class=\"help is-success\">". $success ."</p>";
	}

	protected function getOptions($options)
	{
		$maxlength = isset($options['maxlength']) ? $options['maxlength'] : null;
		$required = isset($options['required']) ? $options['required'] : null;
		$checked = isset($options['checked']) ? $options['checked'] : null;

		$opts = '';
		if (!empty($required))
			$opts .= " required=\"required\"";
		if (!empty($maxlength))
			$opts .= " maxlength=\"". $maxlength ."\"";
		if (!empty($checked))
			$opts .= " checked=\"checked\"";
		$opts .= ">";

		return $opts;
	}

	public function input($name, $label, $options = array(), $error = null, $success = null)
	{
		$type = isset($options['type']) ? $options['type'] : 'text';
		$icon = isset($options['icon']) ? $options['icon'] : null;
		$val = isset($options['val']) ? $options['val'] : $this->getValue($name);


		$inputclass = $this->getInputClass($error, $success);
		$controlClass = $this->getControlClass($icon);

		$render = "<div class=\"field\"><label class=\"label\">". $label ."</label><div class=\"". $controlClass ."\">";
		
		if (!empty($icon))
		    $render .= "<span class=\"icon is-small is-left\"><i class=\"" . $icon . "\"></i></span>";

		$render .= "<input class=\"". $inputclass ."\" type=\"". $type ."\" name=\"". $name ."\" value=\"". $val ."\"";

		$render .= $this->getOptions($options);
		$render .= $this->getMessageFlash($error, $success);
		$render .= "</div></div>";

		return $render;
	}

    public function checkbox($name, $label, $options = array(), $error = null, $success = null)
    {
        $val = isset($options['val']) ? $options['val'] : $this->getValue($name);
        if ($val == true)
            $options['checked'] = 'checked';

        $inputclass = $this->getInputClass($error, $success);

        $render = "<div class=\"field\"><label class=\"label\">". $label ."</label>";

        $render .= "<input type=\"checkbox\" name=\"". $name ."\" value=\"". $val ."\"";

        $render .= $this->getOptions($options);
        $render .= $this->getMessageFlash($error, $success);
        $render .= "</div>";

        return $render;
    }

    public function token($error = null)
    {
		if (empty($_SESSION['token'])) {
		    $_SESSION['token'] = bin2hex(random_bytes(32));
		}
        $render = "<div class=\"field\">";
        $render .= "<input type=\"hidden\" name=\"token\" value=\"".hash_hmac('sha256', 'hashedForm', $_SESSION['token'])."\">";
        $render .= ($error != null) ? "<p class=\"help is-danger\"><i class=\"fa fa-warning\"></i> Le token CSRF n'est pas valide. Rechargez la page !<br></p>" : "";
        $render .= "</div>";

        return $render;
    }

}

?>

<!-- <div class="field">
  <label class="label">Username</label>
  <div class="control has-icons-left has-icons-right">
    <input class="input is-success" type="text" placeholder="Text input" value="bulma">
    <span class="icon is-small is-left">
      <i class="fa fa-user"></i>
    </span>
    <span class="icon is-small is-right">
      <i class="fa fa-check"></i>
    </span>
  </div>
  <p class="help is-success">This username is available</p>
</div> -->

<!-- <div class="field">
  <label class="label">Email</label>
  <div class="control has-icons-left has-icons-right">
    <input class="input is-danger" type="text" placeholder="Email input" value="hello@">
    <span class="icon is-small is-left">
      <i class="fa fa-envelope"></i>
    </span>
    <span class="icon is-small is-right">
      <i class="fa fa-warning"></i>
    </span>
  </div>
  <p class="help is-danger">This email is invalid</p>
</div> -->

<!-- <div class="field">
  <label class="label">Message</label>
  <div class="control">
    <textarea class="textarea" placeholder="Textarea"></textarea>
  </div>
</div> -->