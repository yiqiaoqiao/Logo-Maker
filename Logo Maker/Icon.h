#ifndef FILETREE_ICON_H
#define FILETREE_ICON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Texture.h"

class Icon: public sf::Drawable {
private:
    sf::Sprite sprite;
    std::map<std::string, sf::Texture> texture;
    std::string fileName;
public:
    Icon();
    Icon(std::string str);
    Icon(bool isFile);
    Icon& operator =(const Icon& RHS);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
    void setScale(float x, float y);
    void reAdjustScale(sf::FloatRect rect);
    void setImage(std::string str);
    void setImage(bool isFile);
    sf::Vector2f getPosition() const;
    sf::Vector2f getScale() const;
    sf::Rect<float> getGlobalBound() const;
};


#endif //FILETREE_ICON_H
