#include "ColorList.h"

ColorList::ColorList() {
    enableState(HIDDEN);
    panel.setColor(sf::Color::White);
    panel.setSize(500, 260);
    panel.setPosition(0,0);

    //Red Square
    ColorSquare c1;
    c1.setColor(sf::Color::Red);
    list.push_back(c1);

    //Yellow Square
    ColorSquare c2;
    c2.setColor(sf::Color::Yellow);
    list.push_back(c2);

    //Green Square
    ColorSquare c3;
    c3.setColor(sf::Color::Green);
    list.push_back(c3);

    //Cyan Square
    ColorSquare c4;
    c4.setColor(sf::Color::Cyan);
    list.push_back(c4);

    //Blue Square
    ColorSquare c5;
    c5.setColor(sf::Color::Blue);
    list.push_back(c5);

    //Magenta Square
    ColorSquare c6;
    c6.setColor(sf::Color::Magenta);
    list.push_back(c6);

    //Black Square
    ColorSquare c7;
    c7.setColor(sf::Color::Black);
    list.push_back(c7);

    //White Square
    ColorSquare c8;
    c8.setColor(sf::Color::White);
    list.push_back(c8);

    setPosition(0,0);
    choseColor = sf::Color::Red;
}

void ColorList::setPosition(float x, float y) {
    const int HUNDRED = 100;
    const int SPACE = 20;
    panel.setPosition(x,y);
    list.at(0).setPosition(x+SPACE, y+SPACE);
    list.at(1).setPosition(x+2*SPACE+HUNDRED, y+SPACE);
    list.at(2).setPosition(x+3*SPACE+2*HUNDRED, y+SPACE);
    list.at(3).setPosition(x+4*SPACE+3*HUNDRED, y+SPACE);
    list.at(4).setPosition(x+SPACE, y+2*SPACE+HUNDRED);
    list.at(5).setPosition(x+2*SPACE+HUNDRED, y+2*SPACE+HUNDRED);
    list.at(6).setPosition(x+3*SPACE+2*HUNDRED, y+2*SPACE+HUNDRED);
    list.at(7).setPosition(x+4*SPACE+3*HUNDRED, y+2*SPACE+HUNDRED);
}

void ColorList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!checkState(HIDDEN)){
        window.draw(panel);
        for(int i = 0; i < list.size(); i++){
            window.draw(list.at(i));
        }
    }
}

void ColorList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(!checkState(HIDDEN)){
        for(int i = 0; i < list.size(); i++){
            list.at(i).addEventHandler(window, event);
        }
    }
}

void ColorList::update() {
    //choseColor = sf::Color::Transparent;
    //If any of the color is clicked, set chose color to that color
    if(!checkState(HIDDEN)) {
        for (int i = 0; i < list.size(); i++) {
            if (list.at(i).clicked()) {
                choseColor = list.at(i).getColor();
            }
        }
    }
}

Snapshot &ColorList::getSnapshot() {
    //DO NOTHING
}

void ColorList::applySnapshot(const Snapshot &snapshot) {
    //DO NOTHING
}

sf::Rect<float> ColorList::getGlobalBounds() {
    return panel.getGlobalBound();
}

sf::Color ColorList::getClickedColor() {
    return choseColor;
}

void ColorList::setChoseColor(sf::Color c) {
    choseColor = c;
}

void ColorList::reset() {
    choseColor = sf::Color::Red;
    enableState(HIDDEN);
    for (int i = 0; i < list.size(); i++) {
        list.at(i).reset();
    }
}

