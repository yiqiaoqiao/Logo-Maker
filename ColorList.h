#ifndef LOGOMAKER_COLORLIST_H
#define LOGOMAKER_COLORLIST_H

#include <iostream>
#include <vector>
#include "ColorSquare.h"
#include "GUIComponents.h"

class ColorList: public GUIComponents{
private:
    Box panel;
    std::vector<ColorSquare> list;
    sf::Color choseColor;
    //States states;
public:
    ColorList();
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Rect<float> getGlobalBounds();
    sf::Color getClickedColor();
    void setChoseColor(sf::Color c);
    void reset();
};


#endif //LOGOMAKER_COLORLIST_H
