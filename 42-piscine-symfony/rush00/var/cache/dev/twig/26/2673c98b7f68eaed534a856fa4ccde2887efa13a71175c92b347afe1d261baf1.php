<?php

/* @App/Default/index.html.twig */
class __TwigTemplate_c504ed73d5e475e80a3c3149b74afe94ea196457e6f299915080b0f01ca3089b extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("base.html.twig", "@App/Default/index.html.twig", 1);
        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'body' => array($this, 'block_body'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "base.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e = $this->env->getExtension("Symfony\\Bundle\\WebProfilerBundle\\Twig\\WebProfilerExtension");
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->enter($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@App/Default/index.html.twig"));

        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02 = $this->env->getExtension("Symfony\\Bridge\\Twig\\Extension\\ProfilerExtension");
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->enter($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@App/Default/index.html.twig"));

        $this->parent->display($context, array_merge($this->blocks, $blocks));
        
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->leave($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof);

        
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->leave($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof);

    }

    // line 3
    public function block_title($context, array $blocks = array())
    {
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e = $this->env->getExtension("Symfony\\Bundle\\WebProfilerBundle\\Twig\\WebProfilerExtension");
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->enter($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02 = $this->env->getExtension("Symfony\\Bridge\\Twig\\Extension\\ProfilerExtension");
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->enter($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "title"));

        echo "Accueil";
        
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->leave($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof);

        
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->leave($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof);

    }

    // line 5
    public function block_body($context, array $blocks = array())
    {
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e = $this->env->getExtension("Symfony\\Bundle\\WebProfilerBundle\\Twig\\WebProfilerExtension");
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->enter($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02 = $this->env->getExtension("Symfony\\Bridge\\Twig\\Extension\\ProfilerExtension");
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->enter($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof = new Twig_Profiler_Profile($this->getTemplateName(), "block", "body"));

        // line 6
        echo "  <!-- Main component for a primary marketing message or call to action -->  
  <h1>Moviemon</h1>

  <div class=\"jumbotron\">
    <div class=\"row text-center\">
      <div class=\"col-md-3\">
        <h2>Nouvelle partie</h2>
        <a href=\"";
        // line 13
        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("new_game");
        echo "\" class=\"btn btn-lg btn-primary\">New</a><br><br>
      </div>
      ";
        // line 15
        if ( !(null === $this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "playerName"), "method"))) {
            // line 16
            echo "      <div class=\"col-md-3\">
        <h2>Sauvegarder</h2>
        <a href=\"";
            // line 18
            echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("save_game");
            echo "\" class=\"btn btn-lg btn-success\">Save</a><br><br>
      </div>
      ";
        }
        // line 21
        echo "      <div class=\"col-md-3\">
        <h2>Load</h2>
        ";
        // line 23
        if (( !array_key_exists("sessions", $context) || (twig_length_filter($this->env, (isset($context["sessions"]) ? $context["sessions"] : $this->getContext($context, "sessions"))) <= 0))) {
            // line 24
            echo "          <p>Pas de parties sauvegardées</p>
        ";
        }
        // line 26
        echo "\t\t";
        if (array_key_exists("sessions", $context)) {
            // line 27
            echo "\t\t\t";
            $context['_parent'] = $context;
            $context['_seq'] = twig_ensure_traversable((isset($context["sessions"]) ? $context["sessions"] : $this->getContext($context, "sessions")));
            foreach ($context['_seq'] as $context["_key"] => $context["item"]) {
                // line 28
                echo "\t\t\t<a href=\"";
                echo twig_escape_filter($this->env, $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("load_game", array("name" => $context["item"])), "html", null, true);
                echo "\" class=\"btn btn-lg btn-warning btn-xs\">";
                echo twig_escape_filter($this->env, $context["item"], "html", null, true);
                echo "</a><br>
\t\t\t";
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['_key'], $context['item'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 30
            echo "        ";
        }
        // line 31
        echo "      </div>
      ";
        // line 32
        if ( !(null === $this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "playerName"), "method"))) {
            // line 33
            echo "      <div class=\"col-md-3\">
        <h2>Retourner a la carte</h2>
        <a href=\"";
            // line 35
            echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("cancel_game");
            echo "\" class=\"btn btn-lg btn-danger\">Cancel</a>
      </div>
      ";
        }
        // line 38
        echo "    </div>
  </div>
";
        
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->leave($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof);

        
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->leave($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof);

    }

    public function getTemplateName()
    {
        return "@App/Default/index.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  141 => 38,  135 => 35,  131 => 33,  129 => 32,  126 => 31,  123 => 30,  112 => 28,  107 => 27,  104 => 26,  100 => 24,  98 => 23,  94 => 21,  88 => 18,  84 => 16,  82 => 15,  77 => 13,  68 => 6,  59 => 5,  41 => 3,  11 => 1,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("{% extends 'base.html.twig' %}

{% block title %}Accueil{% endblock %}

{% block body %}
  <!-- Main component for a primary marketing message or call to action -->  
  <h1>Moviemon</h1>

  <div class=\"jumbotron\">
    <div class=\"row text-center\">
      <div class=\"col-md-3\">
        <h2>Nouvelle partie</h2>
        <a href=\"{{ path('new_game') }}\" class=\"btn btn-lg btn-primary\">New</a><br><br>
      </div>
      {% if app.session.get('playerName') is not null %}
      <div class=\"col-md-3\">
        <h2>Sauvegarder</h2>
        <a href=\"{{ path('save_game') }}\" class=\"btn btn-lg btn-success\">Save</a><br><br>
      </div>
      {% endif %}
      <div class=\"col-md-3\">
        <h2>Load</h2>
        {% if sessions is not defined or sessions|length <= 0 %}
          <p>Pas de parties sauvegardées</p>
        {% endif %}
\t\t{% if sessions is defined %}
\t\t\t{% for item in sessions %}
\t\t\t<a href=\"{{ path('load_game', {'name':item}) }}\" class=\"btn btn-lg btn-warning btn-xs\">{{ item }}</a><br>
\t\t\t{% endfor %}
        {% endif %}
      </div>
      {% if app.session.get('playerName') is not null %}
      <div class=\"col-md-3\">
        <h2>Retourner a la carte</h2>
        <a href=\"{{ path('cancel_game') }}\" class=\"btn btn-lg btn-danger\">Cancel</a>
      </div>
      {% endif %}
    </div>
  </div>
{% endblock %}
", "@App/Default/index.html.twig", "/Users/dcognata/piscine_symfony/rush00_save/src/AppBundle/Resources/views/Default/index.html.twig");
    }
}
