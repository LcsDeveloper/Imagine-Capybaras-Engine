
#include "../include/animation.h"

void createAnimation(Animation* animation, Texture* frames, int size, float speed){
    animation->frames = frames;
    animation->size = size;
    animation->speed = speed;
    animation->_time = 0;
    animation->_frame = 0;
}

void runAnimation(Texture* texture, Animation* animation, float deltaTime){
    animation->_time += deltaTime;
    if(animation->speed <= animation->_time){
        animation->_frame++;
        animation->_time = 0;
    }
    if(animation->_frame > animation->size){
        animation->_frame = 0;
    }
    texture->data = (animation->frames + animation->_frame)->data;
    texture->Channels = (animation->frames + animation->_frame)->Channels;
    texture->height = (animation->frames + animation->_frame)->height;
    texture->width = (animation->frames + animation->_frame)->width;
}

void deleteAnimation(Animation* animation){
    for(int i = 0; i < animation->size; i++){
        deleteTexture(animation->frames + i);
    }
}
