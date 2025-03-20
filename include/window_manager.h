#pragma once

#include "glad.h"
#include "glfw3.h"
#define GLT_IMPLEMENTATION
#include "gltext.h"
#include <stdio.h>
#include <stdlib.h>

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


Window createWindow(int width, int height, const char* title);
int isClosedWindow(Window* win);
void clearDisplay();
void updateWindow(Window* win);
void _frameBufferSizeCallback(GLFWwindow* win, int w, int h);
void processInput(Window* win);
void fprocessWindow();
