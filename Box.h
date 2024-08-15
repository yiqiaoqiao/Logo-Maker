#ifndef DROPDOWNMENU_BOX_H
#define DROPDOWNMENU_BOX_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Box: public sf::Drawable {
private:
    sf::RectangleShape box;
    std::string fillColor; //all not capitalized
    std::string outlineColor;
    sf::Vector2f pos;
    sf::Vector2f size;
    float outlineSize;
    int opacity;
public:
    Box();
    Box& operator =(const Box& RHS);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setColor(std::string c);
    void setColor(sf::Color c);
    void setBorderThickness(float s);
    void setBorderColor(std::string c);
    void setBorderColor(sf::Color c);
    sf::Color SFMLColor(const std::string& color);
    //std::string getFillColor();
    sf::Color getFillColor();
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    float getOutlineThickness();
    std::string getOutlineColor();
    sf::Rect<float> getGlobalBound() const;
    void setOpacity(int n);
    int getOpacity();
    sf::RectangleShape getRect();
};


#endif //DROPDOWNMENU_BOX_H
