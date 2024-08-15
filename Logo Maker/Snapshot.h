#ifndef PROJECT1_SNAPSHOT_H
#define PROJECT1_SNAPSHOT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MultiText.h"

class Snapshot {
private:
    std::string text;
    sf::Color textColor;
    sf::Color textListColor;
    sf::Color backgroundColor;
    sf::Color backgroundListColor;
    std::string fontName;
    sf::Vector2f textPosition;
    sf::Vector2f shadowPosition;
    int fontSize;
    int textOpacity;
    int shadowOpacity;
    int backgroundOpacity;
    float skew;
    int value;
    //MultiText multiText;
    //float cursorXPos;
public:
    Snapshot& operator =(const Snapshot& RHS);
    void setText(std::string t);
    void setTextColor(sf::Color c);
    void setTextListColor(sf::Color c);
    void setBackgroundColor(sf::Color c);
    void setBackgroundListColor(sf::Color c);
    void setFontName(std::string name);
    void setTextPosition(sf::Vector2f pos);
    void setShadowPosition(sf::Vector2f pos);
    void setFontSize(int size);
    void setTextOpacity(int o);
    void setShadowOpacity(int o);
    void setBackgroundOpacity(int o);
    void setSkew(float s);
    void setValue(int v);
    //void setMultiText(MultiText m);
    //void setCursorXPos(float x);
    //MultiText getMultiText() const;
    //float getCursorXPos() const;
    int getValue() const;
    std::string getText() const;
    sf::Color getTextColor() const;
    sf::Color getTextListColor() const;
    sf::Color getBackgroundColor() const;
    sf::Color getBackgroundListColor() const;
    std::string getFontName() const;
    sf::Vector2f getTextPosition() const;
    sf::Vector2f getShadowPosition() const;
    int getFontSize() const;
    int getTextOpacity() const;
    int getShadowOpacity() const;
    int getBackgroundOpacity() const;
    float getSkew() const;
};


#endif //PROJECT1_SNAPSHOT_H
