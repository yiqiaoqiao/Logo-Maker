#ifndef PROJECT1_TEXTINPUT_H
#define PROJECT1_TEXTINPUT_H

#include <iostream>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "GUIComponents.h"
#include "TextInputInfo.h"
#include "MultiText.h"
#include "History.h"
#include "Box.h"
#include "Text.h"
#include "MouseEvents.h"

class TextInput: public GUIComponents{
private:
    Box inputBox;
    Text label;
    //sf::Font font;
    Box cursor;
    //sf::RectangleShape button;
    //sf::Text submit;
    TextInputInfo info;
    States states;
    bool inInputBox;
    int count;
    MultiText multiText;
    float cursorXPos;
    Snapshot snapshot;
    //Snapshot snapshot;
    //bool submitPage;
public:
    TextInput();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //void drawShapes(sf::RenderTarget& window);
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    bool isInObject(float x, float y) const;
    bool isInInputBox(float x, float y) const;
    void setLabel(const std::string& str);
    void setLabelSize(int s);
    void setLabelMargin(float t, float b, float l, float r);
    sf::Rect<float> getGlobalBounds();
    void setPosition(float x, float y);
    void setSize(float x, float y);
    bool canAddLetter() const;
    void setLetterSize(int s);
    void setBorderColor(std::string color);
    void setBoxColor(std::string color);
    void setBorderSize(float size);
    std::string getString();
    void check();
    void reset();
    void setText(std::string t);
};


#endif //PROJECT1_TEXTINPUT_H
