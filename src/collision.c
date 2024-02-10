#include "../include/collision.h"

int isColliding(Collision* collider1, Collision* collider2){
    return 
        (((*(collider1->_x) + collider1->scale.x) >= (*(collider2->_x) - collider2->scale.x)) &&
         ((*(collider2->_x) + collider2->scale.x) >= (*(collider1->_x) - collider1->scale.x))) 
        &&
        (((*(collider1->_y) + collider1->scale.y) >= (*(collider2->_y) - collider2->scale.y)) &&
         ((*(collider2->_y) + collider2->scale.y) >= (*(collider1->_y) - collider1->scale.y)));

}