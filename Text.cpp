#include "Text.h"

Text::Text() {
    pos.x = 0;
    pos.y = 0;
    size = 3;
    fillColor = "black";
    outlineColor = "black";
    outlineSize = 0;
    text.setFont(Font::getFont());
    text.setString("");
    text.setPosition(pos);
    text.setFillColor(SFMLColor(fillColor));
    opacity = 0;
    skew = 0;
}

Text &Text::operator=(const Text &RHS) {
    if(this == &RHS){
        return *this;
    }
    fillColor = RHS.fillColor;
    outlineColor = RHS.outlineColor;
    pos = RHS.pos;
    size = RHS.size;
    outlineSize = RHS.outlineSize;
    text.setFillColor(SFMLColor(fillColor));
    text.setCharacterSize(size);
    text.setPosition(pos);
    text.setString(RHS.text.getString());
    text.setOutlineColor(SFMLColor(outlineColor));
    text.setOutlineThickness(outlineSize);
    opacity = RHS.opacity;
    skew = RHS.skew;
    return *this;
}

void Text::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void Text::setPosition(float x, float y) {
    pos.x = x;
    pos.y = y;
    text.setPosition(pos);
}

void Text::setCharacterSize(int s) {
    size = s;
    text.setCharacterSize(s);
}

void Text::setColor(std::string c) {
    fillColor = c;
    text.setFillColor(SFMLColor(fillColor));
}

void Text::setString(std::string s) {
    text.setString(s);
}

void Text::setBorderThickness(float s) {
    outlineSize = s;
    text.setOutlineThickness(outlineSize);
}

void Text::setBorderColor(std::string c) {
    outlineColor = c;
    text.setOutlineColor(SFMLColor(outlineColor));
}

sf::Color Text::SFMLColor(std::string color) {
    sf::Color c = sf::Color::Black;
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
        std::cout << "Color Does not found, Init: Black" << std::endl;
    return c;
}

sf::Color Text::getFillColor() {
    return text.getFillColor();
}

sf::Vector2f Text::getPosition() {
    return pos;
}

int Text::getCharacterSize() {
    return size;
}

float Text::getOutlineThickness() {
    return outlineSize;
}

std::string Text::getOutlineColor() {
    return outlineColor;
}

std::string Text::getString() {
    return text.getString();
}

sf::Rect<float> Text::getGlobalBound() const{
    //std::cout << text.getGlobalBounds().height << std::endl;
    return text.getGlobalBounds();
}

void Text::setColor(sf::Color c) {
    text.setFillColor(c);
}

void Text::setFont(const sf::Font& f) {
    text.setFont(f);
}

void Text::setFont(std::string s) {
    s+=".ttf";
    text.setFont(Font::getFont(s));
}

void Text::setOpacity(int n) {
    sf::Color c = text.getFillColor();
    opacity = n;
    c.a = n;
    text.setFillColor(c);
}

void Text::setSkew(float x, float n) {
    skew = n;
    text.setScale(x, -n);
}

int Text::getOpacity() {
    return opacity;
}

float Text::getSkew() {
    return skew;
}

sf::Text Text::getText() {
    return text;
}

void Text::reAdjustSize(sf::FloatRect rect) {
    //std::cout << "Text reAdjustSize" << std::endl;
    //Make sure that the size if out of bound
    size = 30;
    while(text.getGlobalBounds().width > rect.width || text.getGlobalBounds().height > rect.height){
        //Then shrink the size of the text until it is not out of bound
        std::cout << "shrink" << std::endl;
        size--;
        text.setCharacterSize(size);
    }
    //std::cout << "Text character size: " << size << std::endl;
}