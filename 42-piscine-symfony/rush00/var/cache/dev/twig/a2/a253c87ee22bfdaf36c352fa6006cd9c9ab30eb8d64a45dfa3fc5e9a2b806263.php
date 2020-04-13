<?php

/* @App/Map/fight.html.twig */
class __TwigTemplate_2c79d1c23a8cc3fb6893fffa408e251f8da76116f7a7d262e267c3028f1ce73f extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("base.html.twig", "@App/Map/fight.html.twig", 1);
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
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->enter($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@App/Map/fight.html.twig"));

        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02 = $this->env->getExtension("Symfony\\Bridge\\Twig\\Extension\\ProfilerExtension");
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->enter($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@App/Map/fight.html.twig"));

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

        echo "Fight";
        
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
        echo "<div class=\"row\">

\t<div class=\"col-md-5 col-xs-12\">
\t\t<div class=\"panel panel-default\">
\t\t  <div class=\"panel-heading\">
\t\t  \t<img class=\"panel-img-top\" src=\"";
        // line 11
        echo twig_escape_filter($this->env, $this->env->getExtension('Symfony\Bridge\Twig\Extension\AssetExtension')->getAssetUrl("img/marker.png"), "html", null, true);
        echo "\" alt=\"Card image cap\">
\t\t  \t<h2>Player</h2>
\t\t  </div>
\t\t  <div class=\"panel-body\">
\t\t    <p class=\"card-text\">
\t\t\t<strong>Attaque :</strong> 1
\t\t\t<strong>PV :</strong> ";
        // line 17
        echo twig_escape_filter($this->env, (isset($context["player_life"]) ? $context["player_life"] : $this->getContext($context, "player_life")), "html", null, true);
        echo "<br>
\t\t    </p>
\t\t  </div>
\t\t</div>
\t</div>

\t<div class=\"col-md-2 col-xs-12\">
    \t<a href=\"";
        // line 24
        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("game_atq");
        echo "\" class=\"btn btn-lg btn-danger\">attack</a>
\t</div>

\t<div class=\"col-md-5 col-xs-12\">
\t\t<div class=\"panel panel-default\">
\t\t  <div class=\"panel-heading\">
\t\t  \t<img class=\"panel-img-top\" src=\"";
        // line 30
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["movie"]) ? $context["movie"] : $this->getContext($context, "movie")), "img", array(), "array"), "html", null, true);
        echo "\" alt=\"Card image cap\">
\t\t  \t<h2>";
        // line 31
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["movie"]) ? $context["movie"] : $this->getContext($context, "movie")), "title", array(), "array"), "html", null, true);
        echo "</h2>
\t\t  </div>
\t\t  <div class=\"panel-body\">
\t\t    <p class=\"card-text\">
\t\t\t\t<strong>Attaque :</strong> ";
        // line 35
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["movie"]) ? $context["movie"] : $this->getContext($context, "movie")), "atq", array(), "array"), "html", null, true);
        echo "<br>
\t\t\t\t<strong>Esquive :</strong>  ";
        // line 36
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["movie"]) ? $context["movie"] : $this->getContext($context, "movie")), "esq", array(), "array"), "html", null, true);
        echo "%<br>
\t\t\t\t<strong>PV :</strong> ";
        // line 37
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["movie"]) ? $context["movie"] : $this->getContext($context, "movie")), "pv", array(), "array"), "html", null, true);
        echo "
\t\t    </p>
\t\t  </div>
\t\t</div>
\t</div>

</div>
";
        
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->leave($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof);

        
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->leave($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof);

    }

    public function getTemplateName()
    {
        return "@App/Map/fight.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  122 => 37,  118 => 36,  114 => 35,  107 => 31,  103 => 30,  94 => 24,  84 => 17,  75 => 11,  68 => 6,  59 => 5,  41 => 3,  11 => 1,);
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

{% block title %}Fight{% endblock %}

{% block body %}
<div class=\"row\">

\t<div class=\"col-md-5 col-xs-12\">
\t\t<div class=\"panel panel-default\">
\t\t  <div class=\"panel-heading\">
\t\t  \t<img class=\"panel-img-top\" src=\"{{ asset('img/marker.png')}}\" alt=\"Card image cap\">
\t\t  \t<h2>Player</h2>
\t\t  </div>
\t\t  <div class=\"panel-body\">
\t\t    <p class=\"card-text\">
\t\t\t<strong>Attaque :</strong> 1
\t\t\t<strong>PV :</strong> {{ player_life }}<br>
\t\t    </p>
\t\t  </div>
\t\t</div>
\t</div>

\t<div class=\"col-md-2 col-xs-12\">
    \t<a href=\"{{ path('game_atq') }}\" class=\"btn btn-lg btn-danger\">attack</a>
\t</div>

\t<div class=\"col-md-5 col-xs-12\">
\t\t<div class=\"panel panel-default\">
\t\t  <div class=\"panel-heading\">
\t\t  \t<img class=\"panel-img-top\" src=\"{{ movie['img'] }}\" alt=\"Card image cap\">
\t\t  \t<h2>{{ movie['title'] }}</h2>
\t\t  </div>
\t\t  <div class=\"panel-body\">
\t\t    <p class=\"card-text\">
\t\t\t\t<strong>Attaque :</strong> {{movie['atq']}}<br>
\t\t\t\t<strong>Esquive :</strong>  {{movie['esq']}}%<br>
\t\t\t\t<strong>PV :</strong> {{movie['pv']}}
\t\t    </p>
\t\t  </div>
\t\t</div>
\t</div>

</div>
{% endblock %}", "@App/Map/fight.html.twig", "/Users/dcognata/piscine_symfony/rush00_save/src/AppBundle/Resources/views/Map/fight.html.twig");
    }
}
