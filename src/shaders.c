#include "../include/shaders.h"

void createShaderDefault(Shader* shader){
    const char* _vertex_shader_default =
    "#version 330 core\n"
    "layout (location = 0) in vec3 p;\n"
    "layout (location = 1) in vec3 c;\n"
    "layout (location = 2) in vec2 t;\n"
    "out vec3 fragColor;\n"
    "out vec2 texCoord;\n"
    "uniform mat4 translate_scale;\n"
    "uniform mat4 rot_x;\n"
    "uniform mat4 rot_y;\n"
    "uniform mat4 rot_z;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main(){\n"
    "    gl_Position =  vec4(p, 1.0f) * rot_z * rot_y * rot_x * translate_scale * view * projection;\n"
    "    fragColor = c;\n"
    "    texCoord = t;\n"
    "}\n";

    const char* _fragment_shader_default =
    "#version 330 core\n"
    "out vec4 Color;\n"
    "in vec3 fragColor;\n"
    "in vec2 texCoord;\n"
    "uniform vec4 color;\n"
    "uniform sampler2D image;\n"
    "void main(){\n"
    "    vec4 texColor = texture(image, texCoord) * vec4(fragColor.x + color.x, fragColor.y + color.y, fragColor.z + color.z, color.w);\n"
    "    if(texColor.a < 0.1)\n"
    "        discard;\n"
    "    Color = texColor;\n"
    "}\n";

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &_vertex_shader_default, NULL);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &_fragment_shader_default, NULL);
    glCompileShader(fragment);

    shader->id = glCreateProgram();
    glAttachShader(shader->id, vertex);
    glAttachShader(shader->id, fragment);
    glLinkProgram(shader->id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

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