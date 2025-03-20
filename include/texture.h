#pragma once

#include "glad.h"
#include "glfw3.h"
#include "stb_image.h"

typedef struct{
    int width, height, Channels;
    unsigned int texture_map;
    unsigned char* data;
}Texture;

void createTexture(Texture* texture, const char* texturePath);
void setTexture(Texture* slot, Texture* texture);
void useTexture(Texture* texture);
void unbindTexture();
void deleteTexture(Texture* texture);