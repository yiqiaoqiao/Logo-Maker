#include "ColorSquare.h"

ColorSquare::ColorSquare() {
    square.setSize(100, 100);
    square.setPosition(0,0);
    square.setColor(sf::Color::Red);
    square.setBorderThickness(2);
    square.setBorderColor(sf::Color::Black);
    isClicked = false;
}

void ColorSquare::setColor(sf::Color color) {
    square.setColor(color);
}

void ColorSquare::setOutLineColor(sf::Color color) {
    square.setBorderColor(color);
}

void ColorSquare::setSize(float x, float y) {
    square.setSize(x,y);
}

void ColorSquare::setPosition(float x, float y) {
    square.setPosition(x,y);
}

void ColorSquare::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(square);
}

sf::Rect<float> ColorSquare::getGlobalBounds() {
    return square.getGlobalBound();
}

void ColorSquare::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents::mouseClicked(*this, window)){
        //Click on the object
        isClicked = true;
    }
    else if(MouseEvents::mouseClicked(window, event)){
        //Clicked but not click on this object
        isClicked = false;
    }
}

void ColorSquare::update() {
    //DO NOTHING
}

Snapshot &ColorSquare::getSnapshot() {
    //DO NOTHING
}

void ColorSquare::applySnapshot(const Snapshot &snapshot) {
    //DO NOTHING
}

bool ColorSquare::clicked() const {
    return isClicked;
}

sf::Color ColorSquare::getColor() {
    return square.getFillColor();
}

void ColorSquare::reset() {
    isClicked = false;
}
