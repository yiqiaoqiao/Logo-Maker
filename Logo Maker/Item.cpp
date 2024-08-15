#include "Item.h"

Item::Item() {
    //Display the text in the center of the box
    box.setSize(300,80);
    box.setColor("yellow");
    text.setString("Item");
    text.setCharacterSize(50);
    sf::FloatRect rectB = box.getGlobalBound();
    sf::FloatRect textB = text.getGlobalBound();
    text.setPosition(
            rectB.left + (rectB.width / 2) - (textB.width / 2),
            rectB.top + (rectB.height / 2) - textB.height);
}

Item &Item::operator=(const Item &RHS) {
    if(this == &RHS){
        return *this;
    }
    box = RHS.box;
    text = RHS.text;
    return *this;
}

Item::Item(std::string s) {
    box.setSize(300,80);
    text.setString(s);
    text.setCharacterSize(50);
    sf::FloatRect rectB = box.getGlobalBound();
    sf::FloatRect textB = text.getGlobalBound();
    text.setPosition(
            rectB.left + (rectB.width / 2) - (textB.width / 2),
            rectB.top + (rectB.height / 2) - textB.height);
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(box);
    window.draw(text);
}

void Item::setBoxPosition(float x, float y) {
    box.setPosition(x,y);
    sf::FloatRect rectB = box.getGlobalBound();
    sf::FloatRect textB = text.getGlobalBound();
    text.setPosition(
            rectB.left + (rectB.width / 2) - (textB.width / 2),
            rectB.top + (rectB.height / 2) - textB.height);
}

void Item::setTextPosition(float x, float y) {
    text.setPosition(x,y);
}

void Item::setBoxSize(float x, float y) {
    box.setSize(x,y);
    sf::FloatRect rectB = box.getGlobalBound();
    sf::FloatRect textB = text.getGlobalBound();
    text.setPosition(
            rectB.left + (rectB.width / 2) - (textB.width / 2),
            rectB.top + (rectB.height / 2) - textB.height);
}

void Item::setTextSize(int s) {
    text.setCharacterSize(s);
    sf::FloatRect rectB = box.getGlobalBound();
    sf::FloatRect textB = text.getGlobalBound();
    text.setPosition(
            rectB.left + (rectB.width / 2) - (textB.width / 2),
            rectB.top + (rectB.height / 2) - textB.height);
}

void Item::setText(std::string s) {
    text.setString(s);
    sf::FloatRect rectB = box.getGlobalBound();
    sf::FloatRect textB = text.getGlobalBound();
    text.setPosition(
            rectB.left + (rectB.width / 2) - (textB.width / 2),
            rectB.top + (rectB.height / 2) - textB.height);
}

void Item::setBoxColor(std::string color) {
    //std::cout << "Item color: " << color << std::endl;
    box.setColor(color);
}

void Item::setTextColor(std::string color) {
    text.setColor(color);
}

void Item::setBoxBorderThickness(float size) {
    box.setBorderThickness(size);
}

void Item::setBoxBorderColor(std::string color) {
    box.setBorderColor(color);
}

std::string Item::getTextString() {
    return text.getString();
}

sf::Vector2f Item::getBoxPosition() {
    return box.getPosition();
}

sf::Vector2f Item::getBoxSize() {
    return box.getSize();
}

sf::Vector2f Item::getTextPosition() {
    return text.getPosition();
}

int Item::getTextCharacterSize() {
    return text.getCharacterSize();
}

float Item::getBoxBorderThickness() {
    return box.getOutlineThickness();
}

sf::Rect<float> Item::getGlobalBounds() {
    return box.getGlobalBound();
}

void Item::setBoxBorderColor(sf::Color c) {
    box.setBorderColor(c);
}

void Item::setBoxColor(sf::Color c) {
    box.setColor(c);
}

void Item::setTextColor(sf::Color c) {
    text.setColor(c);
}

