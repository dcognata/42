<?php

namespace Core;

class Autoloader
{
    static function register()
    {
        spl_autoload_register(array(__CLASS__, 'autoloader'));
    }
 
    static function autoloader($class)
    {
        if (strpos($class, __NAMESPACE__ . '\\') === 0)
        {
            $className = str_replace(__NAMESPACE__ . '\\', '', $class);
            $className = str_replace('\\', '/', $className);
            if (!include $className . '.php')
            {
                var_dump($className);
                exit();
            }
        }
    }
}
