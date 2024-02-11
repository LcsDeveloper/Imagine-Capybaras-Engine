#pragma once

#include "glad.h"
#include "glfw3.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int id;
}Shader;

void createShaderDefault(Shader* shader);
void createShader(Shader* shader, const char* vertexPath, const char* fragmentPath);
void setShader(Shader* slot, Shader* shader);
void useShader(Shader* shader);
void setValueShaderBool(Shader* shader, const char* uniformName, int value);
void setValueShaderInt(Shader* shader, const char* uniformName, int value);
void setValueShaderFloat(Shader* shader, const char* uniformName, float value);
void deleteShader(Shader* shader);
