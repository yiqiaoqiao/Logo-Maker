#ifndef LOGOMAKER_FONTLIST_H
#define LOGOMAKER_FONTLIST_H

#include "Menu.h"
#include <iostream>
#include "GUIComponents.h"
#include "History.h"

class FontList: public GUIComponents{
private:
    Menu fontList;
    std::string choseText;
    Snapshot snapshot;
public:
    FontList();
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setInputBoxColor(sf::Color c);
    void setInputBoxBorderColor(sf::Color c);
    void setInputBoxBorderThickness(float s);
    void setTextColor(sf::Color c);
    void setListColor(sf::Color c);
    void setTextSize(int s);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    bool isInInputBox(float x, float y);
    bool isInList(float x, float y);
    sf::Rect<float> getGlobalBounds();
    std::string getText();
    void reset();
    void setChoseText(std::string c);
};


#endif //LOGOMAKER_FONTLIST_H
