#pragma once

#include "glad.h"
#include "glfw3.h"
#include <math.h>

#include "window_manager.h"
#include "shaders.h"
#include "texture.h"
#include "transform.h"
#include "color.h"
#include "collision.h"
#include "cam.h"

typedef struct{
    Position position;
    Scale scale;
    Rotation rotation;
    Color color;
    Shader shader;
    Texture texture;
    Collision collision;
    unsigned int _VAO, _VBO, _EBO;
}Square;

void createSquare(Square* square, Window* win);

void setSquarePosition(Square* square, float x, float y, float z);
//void setSquareColor(Square* square, float r, float g, float b, float a);
//void setSquareScale(Square* square, float x, float y, float z);
//void setSquareRotation(Square* square, float x, float y, float z);

//void setSquareShader(Square* square, Shader shader);
//void setSquareTexture(Square* square, Texture *texture);
//void setSquareCollisionScale(Square* square, float x, float y);

void drawSquare(Square* square, Cam* cam);
void deleteSquare(Square* square);
