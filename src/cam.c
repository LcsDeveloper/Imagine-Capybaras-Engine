
#include "../include/cam.h"

void createCamPerspective(Cam* cam, float fov, float aspect, float n, float f){
    cam->_type = CAM_TYPE_PERSPECTIVE;

    cam->position.x = 0;
    cam->position.y = 0;
    cam->position.z = 0;

    cam->rotation.x = 0;
    cam->rotation.y = 0;
    cam->rotation.z = 0;

    cam->fov = fov;
    cam->a = aspect;
    cam->n = n;
    cam->f = f;
}

void createCamOrthographic(Cam* cam, float l, float r, float t, float b, float n, float f){
    cam->_type = CAM_TYPE_ORTHOGRAPHIC;
    
    cam->position.x = 0;
    cam->position.y = 0;
    cam->position.z = 0;

    cam->rotation.x = 0;
    cam->rotation.y = 0;
    cam->rotation.z = 0;

    cam->l = l;
    cam->r = r;
    cam->t = t;
    cam->b = b;
    cam->n = n;
    cam->f = f;
}

void setCamPosition(Cam* cam, float x, float y, float z){
    cam->position.x = x;
    cam->position.y = y;
    cam->position.z = z;
}

void setCamRotation(Cam* cam, float x, float y, float z){
    cam->rotation.x = x;
    cam->rotation.y = y;
    cam->rotation.z = z;
}