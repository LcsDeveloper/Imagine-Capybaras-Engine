/*IMAGINE CAPYBARAS*/

#pragma once

#include "glad.h"
#include "glfw3.h"
#include "stb_image.h"

#define GLT_IMPLEMENTATION
#include "gltext.h"

#include <math.h>

#define CAM_TYPE_PERSPECTIVE 0
#define CAM_TYPE_ORTHOGRAPHIC 1

typedef struct{
    float x, y, z;
}Position;

typedef struct{
    float x, y, z;
}Scale;

typedef struct{
    float x, y, z;
}Rotation;

typedef struct{
    float r, g, b, a;
}Color;

typedef struct{
    float currentFrame;
    float deltaTime;
    float lastFrame;
}Time;

typedef struct{
    float *_x;
    float *_y;
    float *_z;
    Scale scale;
}Collision;

typedef struct{
    int a, b, c, d, e, f, g, h,
        i, j, k, l, m, n, o, p,
        q, r, s, t, u, v, w, x,
        y, z, esc, space, enter;
    
    int n0, n1, n2, n3, n4, n5, n6, n7, n8, n9;

    int arrow_up, arrow_down, arrow_left, arrow_right;

    int fire1, fire2;
    double mouseX, mouseY;
}Input;

typedef struct{
    GLFWwindow* window;
    Input input;
}Window;

typedef struct{
    unsigned int id;
}Shader;

typedef struct{
    int width, height, Channels;
    unsigned char* data;
}Texture;

typedef struct{
    float l, r, t, b;
    float n, f;
    float fov, a;
    Position position;
    Rotation rotation;
    int _type;
}Cam;

typedef struct{
    Texture* frames;
    int size;
    float speed;
    int _frame;
    float _time;
}Animation;

typedef struct{
    GLTtext *text;
    Color color;
    Position position;
    float size;
}Text;

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

void setPosition(Position* position, float x, float y, float z);
void setScale(Scale* scale, float x, float y, float z);
void setRotation(Rotation* rotation, float x, float y, float z);
void setColor(Color* color, float r, float g, float b, float a);
void getTime(Time* time);
int isColliding(Collision* collider1, Collision* collider2);
Window createWindow(int width, int height);
int isClosedWindow(Window* win);
void clearDisplay();
void updateWindow(Window* win);
void _frameBufferSizeCallback(GLFWwindow* win, int w, int h);
void processInput(Window* win);
void fprocessWindow();
void createShader(Shader* shader, const char* vertexPath, const char* fragmentPath);
void setShader(Shader* slot, Shader* shader);
void useShader(Shader* shader);
void setValueShaderBool(Shader* shader, const char* uniformName, int value);
void setValueShaderInt(Shader* shader, const char* uniformName, int value);
void setValueShaderFloat(Shader* shader, const char* uniformName, float value);
void deleteShader(Shader* shader);
void createTexture(Texture* texture, const char* texturePath);
void setTexture(Texture* slot, Texture* texture);
void useTexture(Texture* texture);
void unbindTexture();
void deleteTexture(Texture* texture);
void createCamPerspective(Cam* cam, float fov, float aspect, float n, float f);
void createCamOrthographic(Cam* cam, float l, float r, float t, float b, float n, float f);
void setCamPosition(Cam* cam, float x, float y, float z);
void setCamRotation(Cam* cam, float x, float y, float z);
void createAnimation(Animation* animation, Texture* frames, int size, float speed);
void runAnimation(Texture* texture, Animation* animation, float deltaTime);
void deleteAnimation(Animation* animation);
void createText(Text* text);
void setText(Text* text, const char* string);
void drawText(Text* text);
void deleteText(Text* text);
void createSquare(Square* square, Window* win);
void setSquarePosition(Square* square, float x, float y, float z);
void drawSquare(Square* square, Cam* cam);
void deleteSquare(Square* square);