#ifndef PROJECT1_TEXTINPUTINFO_H
#define PROJECT1_TEXTINPUTINFO_H

#include <SFML/Graphics.hpp>

struct TextInputInfo{
    //Label Text
    int labelSize;
    sf::Vector2f labelPos;
    //Input Box
    sf::Vector2f inboxSize;
    sf::Vector2f inboxPos;
    //Cursor
    sf::Vector2f cursorSize;
    sf::Vector2f cursorPos;
    //Window
    float width;
    float height;

    TextInputInfo(){
        labelSize = 100;
        labelPos.x = 70;
        labelPos.y = 60;
        inboxSize.x = 530;
        inboxSize.y = 90;
        inboxPos.x = 300;
        inboxPos.y = 90;
        cursorSize.x = 2;
        cursorSize.y = 80;
        cursorPos.x = 310;
        cursorPos.y = 95;
        width = 1000;
        height = 500;
    }
};

#endif //PROJECT1_TEXTINPUTINFO_H
