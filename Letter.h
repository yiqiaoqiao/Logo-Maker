#ifndef MULTITEXT_LETTER_H
#define MULTITEXT_LETTER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Font.h"
#include <string>

class Letter: public sf::Text {
private:
    sf::Text text;
    std::string str;
    //sf::Font font;
    int charSize;
    float x;
    float y;
public:
    Letter(std::string s);
    Letter& operator= (const Letter& RHS);
    sf::Text getText();
    std::string getString();
    char getChar();
    void addCh(char ch);
    void addStr(std::string s);
    void setStr(std::string s);
    //void setFont(sf::Font f);
    void setCharacterSize(int size);
    void setStyle(std::string s);
    void setColor(sf::Color color);
    void setPos(float x, float y);
    int getCharacterSize();
    float getWidth();
    void printPos();
    void getPos(float& x, float& y);
    //std::string getColor();
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //MULTITEXT_LETTER_H
