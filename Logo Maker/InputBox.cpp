#include "InputBox.h"

InputBox::InputBox() {
    //DO Nothing
}

InputBox &InputBox::operator=(const InputBox &RHS) {
    if(this == &RHS){
        return *this;
    }
    inputBox = RHS.inputBox;
    return *this;
}

void InputBox::setBoxPosition(float x, float y) {
    inputBox.setBoxPosition(x,y);
}

void InputBox::setBoxSize(float x, float y) {
    inputBox.setBoxSize(x,y);
}

void InputBox::setTextSize(int size) {
    inputBox.setTextSize(size);
}

void InputBox::setBoxColor(std::string color) {
    inputBox.setBoxColor(color);
}

void InputBox::setTextColor(std::string color) {
    inputBox.setTextColor(color);
}

void InputBox::setText(std::string s) {
    inputBox.setText(s);
}

void InputBox::setBoxBorderThickness(float size) {
    inputBox.setBoxBorderThickness(size);
}

void InputBox::setBoxBorderColor(std::string color) {
    inputBox.setBoxBorderColor(color);
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(inputBox);
}

sf::Vector2f InputBox::getPosition() {
    return inputBox.getBoxPosition();
}

sf::Vector2f InputBox::getSize() {
    return inputBox.getBoxSize();
}

float InputBox::getBoxBorderThickness() {
    return inputBox.getBoxBorderThickness();
}

sf::Rect<float> InputBox::getGlobalBounds() {
    return inputBox.getGlobalBounds();
}

void InputBox::setBoxColor(sf::Color c) {
    inputBox.setBoxColor(c);
}

void InputBox::setTextColor(sf::Color c) {
    inputBox.setTextColor(c);
}

void InputBox::setBoxBorderColor(sf::Color c) {
    inputBox.setBoxBorderColor(c);
}

std::string InputBox::getText() {
    return inputBox.getTextString();
}

