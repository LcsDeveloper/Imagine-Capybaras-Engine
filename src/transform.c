#include "../include/transform.h"

void setPosition(Position* position, float x, float y, float z){
    position->x = x;
    position->y = y;
    position->z = z;
}

void setScale(Scale* scale, float x, float y, float z){
    scale->x *= x;
    scale->y *= y;
    scale->z *= z;
}

void setRotation(Rotation* rotation, float x, float y, float z){
    rotation->x = x;
    rotation->y = y;
    rotation->z = z;
}