#pragma once

#include "texture.h"

typedef struct{
    Texture* frames;
    int size;
    float speed;
    int _frame;
    float _time;
}Animation;

void createAnimation(Animation* animation, Texture* frames, int size, float speed);
void runAnimation(Texture* texture, Animation* animation, float deltaTime);
void deleteAnimation(Animation* animation);
