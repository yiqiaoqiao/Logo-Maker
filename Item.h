#ifndef DROPDOWNMENU_ITEM_H
#define DROPDOWNMENU_ITEM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box.h"
#include "Text.h"
#include "GUIComponents.h"

class Item: public sf::Drawable{
private:
    Box box;
    Text text;
public:
    Item();
    Item(std::string s);
    Item& operator =(const Item& RHS);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setBoxPosition(float x, float y);
    void setTextPosition(float x, float y);
    void setBoxSize(float x, float y);
    void setTextSize(int s);
    void setText(std::string s);
    void setBoxColor(std::string color);
    void setBoxColor(sf::Color c);
    void setTextColor(std::string color);
    void setTextColor(sf::Color c);
    void setBoxBorderThickness(float size);
    void setBoxBorderColor(std::string color);
    void setBoxBorderColor(sf::Color c);
    std::string getTextString();
    sf::Vector2f getBoxPosition();
    sf::Vector2f getTextPosition();
    sf::Vector2f getBoxSize();
    int getTextCharacterSize();
    float getBoxBorderThickness();
    sf::Rect<float> getGlobalBounds();
};


#endif //DROPDOWNMENU_ITEM_H
