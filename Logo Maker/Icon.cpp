#include "Icon.h"

Icon::Icon() {
    sprite.setPosition(0,0);
    texture.insert({"file.png", Texture::getTexture("file.png")});
    texture.insert({"folder.png", Texture::getTexture("folder.png")});
    sprite.setTexture(texture["file.png"]);
    fileName = "file.png";
}

Icon::Icon(std::string str) {
    sprite.setPosition(0,0);
    texture.insert({"file.png", Texture::getTexture("file.png")});
    texture.insert({"folder.png", Texture::getTexture("folder.png")});
    sprite.setTexture(texture[str]);
    fileName = str;
}

Icon::Icon(bool isFile) {
    sprite.setPosition(0,0);
    texture.insert({"file.png", Texture::getTexture("file.png")});
    texture.insert({"folder.png", Texture::getTexture("folder.png")});
    if(isFile) {
        //std::cout << "Set to file" << std::endl;
        fileName = "file.png";
        sprite.setTexture(texture[fileName]);
    }
    else {
        //std::cout << "Set to folder" << std::endl;
        fileName = "folder.png";
        sprite.setTexture(texture[fileName]);
    }
}

Icon &Icon::operator=(const Icon &RHS) {
    if(this == &RHS){
        return *this;
    }
    fileName = RHS.fileName;
    sprite.setPosition(RHS.sprite.getPosition());
    sprite.setScale(RHS.sprite.getScale());
    sprite.setTexture(texture[RHS.fileName]);
    return *this;
}

void Icon::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(sprite);
}

void Icon::setPosition(float x, float y) {
    sprite.setPosition(sf::Vector2f(x,y));
}

void Icon::setScale(float x, float y) {
    sprite.setScale(sf::Vector2f(x,y));
}

sf::Vector2f Icon::getPosition() const {
    return sprite.getPosition();
}

sf::Vector2f Icon::getScale() const {
    return sprite.getScale();
}

sf::Rect<float> Icon::getGlobalBound() const {
    return sprite.getGlobalBounds();
}

void Icon::setImage(std::string str) {
    sprite.setTexture(texture[str]);
}

void Icon::setImage(bool isFile) {
    if(isFile) {
        //std::cout << "Set to file" << std::endl;
        fileName = "file.png";
        sprite.setTexture(texture[fileName]);
    }
    else {
        //std::cout << "Set to folder" << std::endl;
        fileName = "folder.png";
        sprite.setTexture(texture[fileName]);
    }
}

void Icon::reAdjustScale(sf::FloatRect rect) {
    //std::cout << "Icon reAdjustScale" << std::endl;
    //Find the smallest direction
    float smallest = rect.width;
    if(smallest > rect.height)
        smallest = rect.height;

    //find the scale so that it is smaller the smallest size-20
    smallest -= 30;
    float scale = 1;
    while(sprite.getGlobalBounds().width > smallest) {
        scale *= 0.9;
        //td::cout << "Icon width: " << sprite.getGlobalBounds().width << std::endl;
        //std::cout << "smallest width: " << smallest << std::endl;
        sprite.setScale(scale, scale);
    }
}
