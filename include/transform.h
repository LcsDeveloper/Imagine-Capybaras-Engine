#pragma once

typedef struct{
    float x, y, z;
}Position;

typedef struct{
    float x, y, z;
}Scale;

typedef struct{
    float x, y, z;
}Rotation;

void setPosition(Position* position, float x, float y, float z);
void setScale(Scale* scale, float x, float y, float z);
void setRotation(Rotation* rotation, float x, float y, float z);
