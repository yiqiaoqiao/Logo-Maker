#ifndef DROPDOWNMENU_TEXT_H
#define DROPDOWNMENU_TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Font.h"

class Text: public sf::Drawable {
private:
    sf::Text text;
    std::string fillColor; //all not capitalized
    std::string outlineColor;
    sf::Vector2f pos;
    int size;
    float outlineSize;
    int opacity;
    float skew;
public:
    Text();
    Text& operator =(const Text& RHS);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
    void setCharacterSize(int s);
    void setString(std::string s);
    void setColor(std::string c);
    void setColor(sf::Color c);
    void setBorderThickness(float s);
    void setBorderColor(std::string c);
    sf::Color SFMLColor(std::string color);
    sf::Color getFillColor();
    sf::Vector2f getPosition();
    int getCharacterSize();
    float getOutlineThickness();
    std::string getOutlineColor();
    std::string getString();
    //sf::Vector2f getSize();
    sf::Rect<float> getGlobalBound() const;
    void setFont(const sf::Font& f);
    void setFont(std::string s);
    void setOpacity(int n);
    void setSkew(float x, float n);
    int getOpacity();
    float getSkew();
    void reAdjustSize(sf::FloatRect rect);
    sf::Text getText();
};


#endif //DROPDOWNMENU_TEXT_H
