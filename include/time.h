#pragma once

#include "glad.h"
#include "glfw3.h"

typedef struct{
    float currentFrame;
    float deltaTime;
    float lastFrame;
}Time;

void getTime(Time* time);