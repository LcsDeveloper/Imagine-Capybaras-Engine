#include "../include/texture.h"

void createTexture(Texture* texture, const char* texturePath){
    stbi_set_flip_vertically_on_load(1);
    texture->data = stbi_load(texturePath, &(texture->width), &(texture->height), &(texture->Channels), STBI_rgb_alpha);    
}

void setTexture(Texture* slot, Texture* texture){
    slot->Channels = texture->Channels;
    slot->data = texture->data;
    slot->height = texture->height;
    slot->width = texture->width;
}

void useTexture(Texture* texture){
    unsigned int texture_map;
    glGenTextures(1, &texture_map);
    glBindTexture(GL_TEXTURE_2D, texture_map);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->data);
    glGenerateMipmap(GL_TEXTURE_2D);
}

void unbindTexture(){
    glBindTexture(GL_TEXTURE_2D, 0);
}

void deleteTexture(Texture* texture){
    stbi_image_free(texture->data);
}
