#include "../include/time.h"

void getTime(Time* time){
    time->currentFrame = glfwGetTime();
    time->deltaTime = time->currentFrame - time->lastFrame;
    time->lastFrame = time->currentFrame;
}