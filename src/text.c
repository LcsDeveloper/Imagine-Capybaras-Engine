
#include "../include/text.h"


void createText(Text* text){
    gltInit();
    text->text = gltCreateText();
    setColor(&(text->color), 1.0f, 1.0f, 1.0f, 1.0f);
    setPosition(&(text->position), 0.0f, 0.0f, 0.0f);
    text->size = 1.0f;
}

void setText(Text* text, const char* string){
    gltSetText(text->text, string);
}

void drawText(Text* text){
    gltBeginDraw();
    gltColor(text->color.r, text->color.g, text->color.b, text->color.a);
    gltDrawText2D(text->text, text->position.x, text->position.y, text->size);
    gltEndDraw();
}

void deleteText(Text* text){
    gltDeleteText(text->text);
}

