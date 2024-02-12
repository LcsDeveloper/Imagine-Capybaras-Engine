
#include "../include/square.h"

void createSquare(Square* square, Window* win){

    createShaderDefault(&(square->shader));

    square->texture.data = NULL;

    square->position.x = 0;
    square->position.y = 0;
    square->position.z = 0;

    square->scale.x = 1;
    square->scale.y = 1;
    square->scale.z = 0;

    square->rotation.x = 0;
    square->rotation.y = 0;
    square->rotation.z = 0;

    square->color.r = 1;
    square->color.g = 1;
    square->color.b = 1;
    square->color.a = 1;

    int w, h;
    glfwGetWindowSize(win->window, &w, &h);

    float Wn, Hn, x, y;
    if(w > h){
        y = (float)((h/2)*(w/h));
        x = (float)(h/2);
    }else{
        x = (float)((w/2)*(h/w));
        y = (float)(w/2);
    }
    Wn = (1/(float)(w))*(x);
    Hn = (1/(float)(h))*(y);

    square->collision._x = &(square->position.x);
    square->collision._y = &(square->position.y);
    square->collision._z = &(square->position.z);
    square->collision.scale.x = Wn/2;
    square->collision.scale.y = Hn/2;
    square->collision.scale.z = 0.0f;

    float v[] = {
        -Wn/2, -Hn/2, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        -Wn/2,  Hn/2, 0.0f,   0.0f, 0.0f, 0.0f,   0.0f, 1.0f,
         Wn/2, -Hn/2, 0.0f,   0.0f, 0.0f, 0.0f,   1.0f, 0.0f,
         Wn/2,  Hn/2, 0.0f,   0.0f, 0.0f, 0.0f,   1.0f, 1.0f
    };

    unsigned int i[] = {
        0, 1, 2,
        1, 2, 3
    };

    glGenVertexArrays(1, &(square->_VAO));
    glGenBuffers(1, &(square->_VBO));
    glGenBuffers(1, &(square->_EBO));

    glBindVertexArray(square->_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, square->_VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, square->_EBO);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(i), i, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

//void setSquarePosition(Square* square, float x, float y, float z){
//    setPosition(&(square->position), x, y, z);
//    setPosition(&(square->collision.position), x, y, z);
//}

/*void setSquareColor(Square* square, float r, float g, float b, float a){
    square->color.r = r;
    square->color.g = g;
    square->color.b = b;
    square->color.a = a;
}

void setSquareScale(Square* square, float x, float y, float z){
    square->scale.x = x;
    square->scale.y = y;
    square->scale.z = z;
}

void setSquareRotation(Square* square, float x, float y, float z){
    square->rotation.x = x;
    square->rotation.y = y;
    square->rotation.z = z;
}

void setSquareShader(Square* square, Shader shader){
    square->shader = shader;
}

void setSquareTexture(Square* square, Texture *texture){
    square->texture = texture;
}

void setSquareCollisionScale(Square* square, float x, float y){
    square->collision.scale.x *= x;
    square->collision.scale.y *= y;
}*/

void drawSquare(Square* square, Cam* cam){
    const float cam_posi[] = {
        1.0f, 0.0f, 0.0f, cam->position.x,
        0.0f, 1.0f, 0.0f, cam->position.y,
        0.0f, 0.0f, 1.0f, cam->position.z,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    const float ts[] = {
        square->scale.x, 0.0f           , 0.0f           , square->position.x,
        0.0f           , square->scale.y, 0.0f           , square->position.y,
        0.0f           , 0.0f           , square->scale.z, square->position.z,
        0.0f           , 0.0f           , 0.0f           , 1.0f
    };

    const float rx[] = {
        1.0f, 0.0f                   , 0.0f                    , 0.0f,
        0.0f, cos(square->rotation.x), -sin(square->rotation.x), 0.0f,
        0.0f, sin(square->rotation.x), cos(square->rotation.x) , 0.0f,
        0.0f, 0.0f                   , 0.0f                    , 1.0f 
    };

    const float ry[] = {
        cos(square->rotation.y) , 0.0f, sin(square->rotation.y), 0.0f,
        0.0f                    , 1.0f, 0.0f                   , 0.0f,
        -sin(square->rotation.y), 0.0f, cos(square->rotation.y), 0.0f,
        0.0f                    , 0.0f, 0.0f                   , 1.0f 
    };

    const float rz[] = {
        cos(square->rotation.z) , -sin(square->rotation.z), 0.0f, 0.0f,
        sin(square->rotation.z) , cos(square->rotation.z) , 0.0f, 0.0f,
        0.0f                    , 0.0f                    , 1.0f, 0.0f,
        0.0f                    , 0.0f                    , 0.0f, 1.0f 
    };

    if(square->texture.data != NULL){
        useTexture(&(square->texture));
    }

    useShader(&(square->shader));
    glUniform4f(glGetUniformLocation(square->shader.id, "color"), square->color.r, square->color.g, square->color.b, square->color.a);
    glUniformMatrix4fv(glGetUniformLocation(square->shader.id, "translate_scale"), 1, GL_FALSE, ts);
    glUniformMatrix4fv(glGetUniformLocation(square->shader.id, "rot_x"), 1, GL_FALSE, rx);
    glUniformMatrix4fv(glGetUniformLocation(square->shader.id, "rot_y"), 1, GL_FALSE, ry);
    glUniformMatrix4fv(glGetUniformLocation(square->shader.id, "rot_z"), 1, GL_FALSE, rz);

    glUniformMatrix4fv(glGetUniformLocation(square->shader.id, "view"), 1, GL_FALSE, cam_posi);

    if(cam->_type == CAM_TYPE_PERSPECTIVE){
        float c, a, n, f;
        c = 1/tan((cam->fov * (M_PI/180.0f))/2);
        a = cam->a;
        n = cam->n;
        f = cam->f;
        const float persp[] = {
            c/a , 0.0f, 0.0f       , 0.0f,
            0.0f, c   , 0.0f       , 0.0f,
            0.0f, 0.0f, (f+n)/(n-f), (2*f*n)/(n-f),
            0.0f, 0.0f, -1.0f      , 0.0f
        };
        glUniformMatrix4fv(glGetUniformLocation(square->shader.id, "projection"), 1, GL_FALSE, persp);
    }else if(cam->_type == CAM_TYPE_ORTHOGRAPHIC){
        float l, r, b, t, n, f;
        l = cam->l;
        r = cam->r;
        b = cam->b;
        t = cam->t;
        n = cam->n;
        f = cam->f;
        const float ortho[] = {
            2/(r-l), 0.0f   , -((r+l)/(r-l)), -((r+l)/(r-l)),
            0.0f   , 2/(t-b), -((t+b)/(t-b)), -((t+b)/(t-b)),
            0.0f   , 0.0f   , -2/(f-n)      , -((f+n)/(f-n)),
            0.0f   , 0.0f   , 0.0f          , 1.0f
        };
        glUniformMatrix4fv(glGetUniformLocation(square->shader.id, "projection"), 1, GL_FALSE, ortho);    
    }
    
    glBindVertexArray(square->_VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    unbindTexture();
}

void deleteSquare(Square* square){
    deleteShader(&(square->shader));
    glDeleteBuffers(1, &(square->_VBO));
    glDeleteBuffers(1, &(square->_EBO));
    glDeleteVertexArrays(1, &(square->_VAO));
}
