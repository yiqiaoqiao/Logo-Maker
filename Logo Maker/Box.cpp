#include "Box.h"

#include <utility>

Box::Box() {
    pos.x = 0;
    pos.y = 0;
    size.x = 100;
    size.y = 100;
    fillColor = "white";
    outlineColor = "black";
    outlineSize = 0;
    box.setPosition(pos);
    box.setSize(size);
    box.setFillColor(SFMLColor(fillColor));
}

Box &Box::operator=(const Box& RHS) {
    if(this == &RHS){
        return *this;
    }
    fillColor = RHS.fillColor;
    outlineColor = RHS.outlineColor;
    pos = RHS.pos;
    size = RHS.size;
    outlineSize = RHS.outlineSize;
    box.setFillColor(SFMLColor(fillColor));
    box.setSize(size);
    box.setPosition(pos);
    box.setOutlineColor(SFMLColor(outlineColor));
    box.setOutlineThickness(outlineSize);
    return *this;
}


void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
}

void Box::setPosition(float x, float y) {
    pos.x = x;
    pos.y = y;
    box.setPosition(pos);
}

void Box::setSize(float x, float y) {
    size.x = x;
    size.y = y;
    box.setSize(size);
}

void Box::setColor(std::string c) {
    fillColor = std::move(c);
    box.setFillColor(SFMLColor(fillColor));
    //std::cout << "SetColor: " << fillColor << std::endl;
}

void Box::setBorderThickness(float s){
    outlineSize = s;
    box.setOutlineThickness(outlineSize);
}

void Box::setBorderColor(std::string c) {
    outlineColor = std::move(c);
    box.setOutlineColor(SFMLColor(outlineColor));
}

sf::Color Box::SFMLColor(const std::string& color) {
    sf::Color c;
    if(color == "black")
        c = sf::Color::Black;
    else if(color == "yellow")
        c = sf::Color::Yellow;
    else if(color == "blue")
        c = sf::Color::Blue;
    else if(color == "red")
        c = sf::Color::Red;
    else if(color == "green")
        c = sf::Color::Green;
    else if(color == "white")
        c = sf::Color::White;
    else if(color == "cyan")
        c = sf::Color::Cyan;
    else if(color == "magenta")
        c = sf::Color::Magenta;
    else if(color == "transparent")
        c = sf::Color::Transparent;
    else
        std::cout << "Color Does not found" << std::endl;
    //std::cout << "SFML COLOR: " << color << std::endl;
    //std::cout << "SFML COLOR: " << fillColor << std::endl;
    return c;
}

/*
std::string Box::getFillColor() {
    //std::cout << "Get Filled Color: " << fillColor << std::endl << std::endl;
    return fillColor;
}
 */

sf::Vector2f Box::getPosition() {
    return pos;
}

sf::Vector2f Box::getSize() {
    return size;
}

float Box::getOutlineThickness() {
    return outlineSize;
}

std::string Box::getOutlineColor() {
    return outlineColor;
}

sf::Rect<float> Box::getGlobalBound() const{
    return box.getGlobalBounds();
}

void Box::setColor(sf::Color c) {
    box.setFillColor(c);
}

void Box::setBorderColor(sf::Color c) {
    box.setOutlineColor(c);
}

sf::Color Box::getFillColor() {
    return box.getFillColor();
}

void Box::setOpacity(int n) {
    sf::Color c = box.getFillColor();
    c.a = n;
    box.setFillColor(c);
    opacity = n;
}

int Box::getOpacity() {
    return opacity;
}

sf::RectangleShape Box::getRect() {
    return box;
}

