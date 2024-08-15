#include "Texture.h"

sf::Texture Texture::texture;

void Texture::loadTexture(std::string str) {
    if(!texture.loadFromFile(str)){
        std::cout<<"Image Class: Image failed to load"<<std::endl;
        exit(-1);
    }
}

sf::Texture &Texture::getTexture(std::string str) {
    loadTexture(str);
    return texture;
}
