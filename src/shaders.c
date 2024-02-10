#include "../include/shaders.h"


void createShader(Shader* shader, const char* vertexPath, const char* fragmentPath){
    char* vertexShader = (char *) malloc(1);
    char* fragmentShader = (char *) malloc(1);
    
    FILE* vertexShaderFile;
    vertexShaderFile = fopen(vertexPath, "r");
    
    FILE* fragmentShaderFile;
    fragmentShaderFile = fopen(fragmentPath, "r");
    
    int i;
    char rc;
    
    rc = '\0';
    for(i = 1; rc != EOF; i++){
        vertexShader = (char *) realloc(vertexShader, i);
        rc = getc(vertexShaderFile);
        vertexShader[i-1] = rc;
    }
    vertexShader[i-2] = '\0';
    
    rc = '\0';
    for(i = 1; rc != EOF; i++){
        fragmentShader = (char *) realloc(fragmentShader, i);
        rc = getc(fragmentShaderFile);
        fragmentShader[i-1] = rc;
    }
    fragmentShader[i-2] = '\0';

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexShader, NULL);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentShader, NULL);
    glCompileShader(fragment);

    shader->id = glCreateProgram();
    glAttachShader(shader->id, vertex);
    glAttachShader(shader->id, fragment);
    glLinkProgram(shader->id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    fclose(vertexShaderFile);
    fclose(fragmentShaderFile);
    free(vertexShader);
    free(fragmentShader);
}

void setShader(Shader* slot, Shader* shader){
    slot = shader;
    slot->id = shader->id;
}

void useShader(Shader* shader){
    glUseProgram(shader->id);
}

void setValueShaderBool(Shader* shader, const char* uniformName, int value){
    glUniform1i(glGetUniformLocation(shader->id, uniformName), value);
}

void setValueShaderInt(Shader* shader, const char* uniformName, int value){
    glUniform1i(glGetUniformLocation(shader->id, uniformName), value);
}

void setValueShaderFloat(Shader* shader, const char* uniformName, float value){
    glUniform1f(glGetUniformLocation(shader->id, uniformName), value);
}

void deleteShader(Shader* shader){
    glDeleteShader(shader->id);
}