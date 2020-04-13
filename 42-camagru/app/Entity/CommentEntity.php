<?php

namespace Camagru\Entity;

use Core\Entity\Entity;

/**
* 
*/
class CommentEntity extends Entity
{
    public function findBy($field, $value)
    {
        return $this->query('SELECT *, comment.id AS c_id, user.id AS u_id FROM `'. $this->table .'` RIGHT JOIN `user` ON comment.user_id = user.id WHERE '. $field .' = ? ORDER BY comment.id DESC', [$value], false);
    }
}
