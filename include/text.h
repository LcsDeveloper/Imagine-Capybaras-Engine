#pragma once

#include "glad.h"
#define GLT_IMPLEMENTATION
#include "gltext.h"
#include "transform.h"
#include "color.h"

typedef struct{
    GLTtext *text;
    Color color;
    Position position;
    float size;
}Text;

void createText(Text* text);
void setText(Text* text, const char* string);
void drawText(Text* text);
void deleteText(Text* text);
