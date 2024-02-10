#pragma once

#include "transform.h"

#define CAM_TYPE_PERSPECTIVE 0
#define CAM_TYPE_ORTHOGRAPHIC 1

typedef struct{
    float l, r, t, b;
    float n, f;
    float fov, a;
    Position position;
    Rotation rotation;
    int _type;
}Cam;

void createCamPerspective(Cam* cam, float fov, float aspect, float n, float f);
void createCamOrthographic(Cam* cam, float l, float r, float t, float b, float n, float f);
void setCamPosition(Cam* cam, float x, float y, float z);
void setCamRotation(Cam* cam, float x, float y, float z);
