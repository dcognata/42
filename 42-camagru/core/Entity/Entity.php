<?php

namespace Core\Entity;

use Core\Database\MysqlConnection;

/**
* 
*/
class Entity
{
    protected $table;
    protected $db;

    public function __construct(MysqlConnection $db)
    {
        $this->db = $db;
        if (is_null($this->table))
        {
            $name = explode('\\', get_class($this));
            $name = end($name);
            $this->table = strtolower(str_replace('Entity', '', $name));
        }
    }

    public function findAll()
    {
        return $this->query('SELECT * FROM `'. $this->table.'`');
    }

    public function find($id)
    {
        return $this->query('SELECT * FROM `'. $this->table .'` WHERE id = ?', [$id], true);
    }

    public function findBy($field, $value)
    {
        return $this->query('SELECT * FROM `'. $this->table .'` WHERE '. $field .' = ?', [$value], false);
    }

    public function findOneBy($field, $value)
    {
        return $this->query('SELECT * FROM `'. $this->table .'` WHERE '. $field .' = ?', [$value], true);
    }

    public function update($id, $fields)
    {
        $datas = [];
        $attributes = [];
        foreach ($fields as $key => $value) {
            $datas[] = "$key = ?";
            $attributes[] = $value;
        }
        $attributes[] = $id;
        $datas = implode(', ', $datas);
        return $this->query('UPDATE `'. $this->table .'` SET '. $datas .' WHERE id = ?', $attributes, true);
    }

    public function create($fields)
    {
        $datas = [];
        $attributes = [];
        foreach ($fields as $key => $value) {
            $datas[] = "$key = ?";
            $attributes[] = $value;
        }
        $datas = implode(', ', $datas);
        return $this->query('INSERT INTO `'. $this->table .'` SET '. $datas, $attributes, true);
    }

    public function remove($id)
    {
        return $this->query('DELETE FROM `'. $this->table .'` WHERE id = ?', [$id], true);
    }

    public function query($repository, $attribute = null, $one = false)
    {
        if ($attribute) {
            return $this->db->prepare(
                $repository,
                $attribute,
                str_replace('Entity', 'Repository', get_class($this)),
                $one
            );
        } else {
            return $this->db->query(
                $repository,
                str_replace('Entity', 'Repository', get_class($this)),
                $one
            );
        }
    }

}
