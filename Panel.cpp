#include "Panel.h"

Panel::Panel() {
    fontName = "Roboto";
    text.setString("");
    shadow.setString("");
    text.setColor(sf::Color::Red);
    text.setCharacterSize(50);
    //sf::Color c(65,65,65);
    shadow.setColor(sf::Color::White);
    //text.setPosition(10,10);
    panel.setColor(sf::Color::Black);
    if (!font.loadFromFile("Roboto Bold.ttf")){
        std::cout<<"Panel Class: Font failed to load"<<std::endl;
        exit(-1);
    }
    text.setFont(font);
    shadow.setFont(font);
}

void Panel::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(panel);
    window.draw(text);
    window.draw(shadow);
}

void Panel::setText(std::string s) {
    text.setString(s);
    shadow.setString(s);
    //setTextMiddle();
}

void Panel::setPosition(float x, float y) {
    panel.setPosition(x,y);
    text.setPosition(x,y);
    shadow.setPosition(x,y);
}

void Panel::setSize(float x, float y) {
    panel.setSize(x,y);
}

void Panel::setBackgroundColor(sf::Color c) {
    panel.setColor(c);
}

void Panel::setTextMiddle() {
    sf::Rect<float> rectB = panel.getGlobalBound();
    sf::Rect<float> textB = text.getGlobalBound();
    /*
    text.setPosition(rectB.left + (rectB.width / 2) - (textB.width / 2),
                     rectB.top + (rectB.height / 2) - (textB.height / 2));
                     */
    text.setPosition(10,
                     rectB.top + (rectB.height / 2) - (textB.height / 2));
}

void Panel::setFontSize(int size) {
    text.setCharacterSize(size);
    shadow.setCharacterSize(size);
}

void Panel::setTextColor(sf::Color c) {
    text.setColor(c);
}

void Panel::setFont(std::string s) {
    fontName = s;
    //std::cout << s << std::endl;
    s+=".ttf";
    if (!font.loadFromFile(s)){
        std::cout<<"Panel Class: Font failed to load"<<std::endl;
        exit(-1);
    }
    text.setFont(font);
    shadow.setFont(font);
}

void Panel::setTextPosition(float x, float y) {
    sf::Rect<float> bounds = panel.getGlobalBound();
    text.setPosition(bounds.left+x, bounds.top+y);
}

void Panel::setOpacity(int t, int s, int b) {
    text.setOpacity(t);
    shadow.setOpacity(s);
    panel.setOpacity(b);
}

void Panel::setSkew(float n) {
    shadow.setSkew(1.0f, n);
}

sf::Rect<float> Panel::getGlobalBound() {
    return panel.getGlobalBound();
}

void Panel::setShadowPosition(float x, float y) {
    sf::Rect<float> bounds = panel.getGlobalBound();
    sf::Rect<float> tBounds = shadow.getGlobalBound();
    shadow.setPosition(bounds.left+x, bounds.top+y+tBounds.height);
}

std::string Panel::getString() {
    return text.getString();
}

sf::Color Panel::getTextColor() {
    return text.getFillColor();
}

sf::Color Panel::getBackgroundColor() {
    return panel.getFillColor();
}

std::string Panel::getFontName() {
    return fontName;
}

sf::Vector2f Panel::getTextPosition() {
    return text.getPosition();
}

int Panel::getFontSize() {
    return text.getCharacterSize();
}

int Panel::getTextOpacity() {
    return text.getOpacity();
}

int Panel::getShadowOpacity() {
    return shadow.getOpacity();
}

int Panel::getBackgroundOpacity() {
    return panel.getOpacity();
}

float Panel::getSkew() {
    return shadow.getSkew();
}

sf::Vector2f Panel::getShadowPosition() {
    return shadow.getPosition();
}

sf::Text Panel::getText() {
    return text.getText();
}

sf::Text Panel::getShadow() {
    return shadow.getText();
}

sf::RectangleShape Panel::getPanel() {
    return panel.getRect();
}

