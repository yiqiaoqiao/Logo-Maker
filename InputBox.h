#ifndef DROPDOWNMENU_INPUTBOX_H
#define DROPDOWNMENU_INPUTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Item.h"

class InputBox: public sf::Drawable{
private:
    Item inputBox;
public:
    InputBox();
    InputBox& operator =(const InputBox& RHS);
    void setBoxPosition(float x, float y);
    void setBoxSize(float x, float y);
    void setTextSize(int size);
    void setBoxColor(std::string color);
    void setBoxColor(sf::Color c);
    void setTextColor(std::string color);
    void setTextColor(sf::Color c);
    void setText(std::string s);
    void setBoxBorderThickness(float size);
    void setBoxBorderColor(std::string color);
    void setBoxBorderColor(sf::Color c);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    float getBoxBorderThickness();
    sf::Rect<float> getGlobalBounds();
    std::string getText();
};


#endif //DROPDOWNMENU_INPUTBOX_H
