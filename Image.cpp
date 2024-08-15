#include "Image.h"

sf::Image Image::image;

void Image::loadImage(std::string str) {
    if(!image.loadFromFile(str)){
        std::cout<<"Image Class: Image failed to load"<<std::endl;
        exit(-1);
    }
}

sf::Image &Image::getImage(std::string str) {
    loadImage(str);
    return image;
}
