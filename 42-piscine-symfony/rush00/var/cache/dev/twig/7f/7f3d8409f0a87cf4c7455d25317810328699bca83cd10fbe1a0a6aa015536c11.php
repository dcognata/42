<?php

/* @App/Map/case.html.twig */
class __TwigTemplate_07f595c8773e0bbc13ca345960d3dd4f43e0996fb54cbcf6d86beba10bcb3cd3 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        // line 1
        $this->parent = $this->loadTemplate("base.html.twig", "@App/Map/case.html.twig", 1);
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
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->enter($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@App/Map/case.html.twig"));

        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02 = $this->env->getExtension("Symfony\\Bridge\\Twig\\Extension\\ProfilerExtension");
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->enter($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof = new Twig_Profiler_Profile($this->getTemplateName(), "template", "@App/Map/case.html.twig"));

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

        echo "Jeu";
        
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
  <div class=\"col-md-10\">
  ";
        // line 8
        $context["map"] = $this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "map"), "method");
        // line 9
        echo "    <table class=\"table table-dark\">
      <tbody>
        ";
        // line 11
        $context['_parent'] = $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["map"]) ? $context["map"] : $this->getContext($context, "map")));
        foreach ($context['_seq'] as $context["key"] => $context["item"]) {
            // line 12
            echo "        <tr>
          ";
            // line 13
            $context['_parent'] = $context;
            $context['_seq'] = twig_ensure_traversable($context["item"]);
            foreach ($context['_seq'] as $context["k"] => $context["ite"]) {
                // line 14
                echo "          <td width=\"20%\" height=\"200\" class=\"text-center\" 
            ";
                // line 15
                if ((($this->getAttribute($this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "playerPos"), "method"), "x", array()) == $context["k"]) && ($this->getAttribute($this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "playerPos"), "method"), "y", array()) == $context["key"]))) {
                    // line 16
                    echo "              style=\"background-size: 100%;
                  background-repeat: no-repeat;
                  background-image:url('";
                    // line 18
                    echo twig_escape_filter($this->env, $this->env->getExtension('Symfony\Bridge\Twig\Extension\AssetExtension')->getAssetUrl("img/marker.png"), "html", null, true);
                    echo "')\"
            ";
                } else {
                    // line 20
                    echo "              bgcolor=\"";
                    echo twig_escape_filter($this->env, $context["ite"], "html", null, true);
                    echo "\"
            ";
                }
                // line 21
                echo ">
            ";
                // line 22
                if ((($this->getAttribute($this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "playerPos"), "method"), "x", array()) == $context["k"]) && ($this->getAttribute($this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "playerPos"), "method"), "y", array()) == $context["key"]))) {
                    // line 23
                    echo "              ";
                    if (($this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "firstMove"), "method") != true)) {
                        echo "<a href=\"";
                        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("map_game_fight");
                        echo "\" class=\"btn btn-danger\">Fight</a>";
                    }
                    // line 24
                    echo "            ";
                }
                // line 25
                echo "          </td>
          ";
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['k'], $context['ite'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 27
            echo "        </tr>
        ";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['key'], $context['item'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 29
        echo "      </tbody>
    </table>
  </div>
  <div class=\"col-md-2\">
    <div class=\"jumbotron\" style=\"display:flex; flex-direction: column; align-items:center\">
      <div>
        <a href=\"";
        // line 35
        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("map_game_direct", array("direction" => 1));
        echo "\">top</a>
      </div>
      <div style=\"display:inherit; flex-direction: row; align-items:center\">
        <a href=\"";
        // line 38
        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("map_game_direct", array("direction" => 0));
        echo "\">left</a>
        <div style=\"width:100px; height:100px; background-color:";
        // line 39
        echo twig_escape_filter($this->env, (isset($context["color"]) ? $context["color"] : $this->getContext($context, "color")), "html", null, true);
        echo ";display:inherit; align-items:center; justify-content: center;\">
          ";
        // line 40
        if (($this->getAttribute($this->getAttribute((isset($context["app"]) ? $context["app"] : $this->getContext($context, "app")), "session", array()), "get", array(0 => "firstMove"), "method") != true)) {
            echo "<a href=\"";
            echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("map_game_fight");
            echo "\" class=\"btn btn-danger\">Fight</a>";
        }
        // line 41
        echo "        </div>
        <a href=\"";
        // line 42
        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("map_game_direct", array("direction" => 2));
        echo "\">right</a>
      </div>
      <div>
        <a href=\"";
        // line 45
        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("map_game_direct", array("direction" => 3));
        echo "\">bottom</a>
      </div>
    </div>
    <div class=\"text-center\">
      <a href=\"";
        // line 49
        echo $this->env->getExtension('Symfony\Bridge\Twig\Extension\RoutingExtension')->getPath("map_game");
        echo "\" class=\"btn btn-lg btn-success\">Voir la map</a>
    </div>
  </div>
</div>
";
        
        $__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02->leave($__internal_319393461309892924ff6e74d6d6e64287df64b63545b994e100d4ab223aed02_prof);

        
        $__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e->leave($__internal_085b0142806202599c7fe3b329164a92397d8978207a37e79d70b8c52599e33e_prof);

    }

    public function getTemplateName()
    {
        return "@App/Map/case.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  182 => 49,  175 => 45,  169 => 42,  166 => 41,  160 => 40,  156 => 39,  152 => 38,  146 => 35,  138 => 29,  131 => 27,  124 => 25,  121 => 24,  114 => 23,  112 => 22,  109 => 21,  103 => 20,  98 => 18,  94 => 16,  92 => 15,  89 => 14,  85 => 13,  82 => 12,  78 => 11,  74 => 9,  72 => 8,  68 => 6,  59 => 5,  41 => 3,  11 => 1,);
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

{% block title %}Jeu{% endblock %}

{% block body %}
<div class=\"row\">
  <div class=\"col-md-10\">
  {% set map = app.session.get('map') %}
    <table class=\"table table-dark\">
      <tbody>
        {% for key,item in map %}
        <tr>
          {% for k,ite in item %}
          <td width=\"20%\" height=\"200\" class=\"text-center\" 
            {% if app.session.get('playerPos').x == k and app.session.get('playerPos').y == key %}
              style=\"background-size: 100%;
                  background-repeat: no-repeat;
                  background-image:url('{{ asset('img/marker.png')}}')\"
            {% else %}
              bgcolor=\"{{ ite }}\"
            {% endif %}>
            {% if app.session.get('playerPos').x == k and app.session.get('playerPos').y == key %}
              {% if app.session.get('firstMove') != true %}<a href=\"{{ path('map_game_fight') }}\" class=\"btn btn-danger\">Fight</a>{% endif %}
            {% endif %}
          </td>
          {% endfor %}
        </tr>
        {% endfor %}
      </tbody>
    </table>
  </div>
  <div class=\"col-md-2\">
    <div class=\"jumbotron\" style=\"display:flex; flex-direction: column; align-items:center\">
      <div>
        <a href=\"{{ path(\"map_game_direct\", {'direction' : 1})}}\">top</a>
      </div>
      <div style=\"display:inherit; flex-direction: row; align-items:center\">
        <a href=\"{{ path(\"map_game_direct\", {'direction' : 0})}}\">left</a>
        <div style=\"width:100px; height:100px; background-color:{{color}};display:inherit; align-items:center; justify-content: center;\">
          {% if app.session.get('firstMove') != true %}<a href=\"{{ path('map_game_fight') }}\" class=\"btn btn-danger\">Fight</a>{% endif %}
        </div>
        <a href=\"{{ path(\"map_game_direct\", {'direction' : 2})}}\">right</a>
      </div>
      <div>
        <a href=\"{{ path(\"map_game_direct\", {'direction' : 3})}}\">bottom</a>
      </div>
    </div>
    <div class=\"text-center\">
      <a href=\"{{ path('map_game') }}\" class=\"btn btn-lg btn-success\">Voir la map</a>
    </div>
  </div>
</div>
{% endblock %}
", "@App/Map/case.html.twig", "/Users/dcognata/piscine_symfony/rush00_save/src/AppBundle/Resources/views/Map/case.html.twig");
    }
}
