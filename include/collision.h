#pragma once

#include "transform.h"

typedef struct{
    float *_x;
    float *_y;
    float *_z;
    Scale scale;
}Collision;

int isColliding(Collision* collider1, Collision* collider2);
