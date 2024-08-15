#ifndef LOGOMAKER_COLORSQUARE_H
#define LOGOMAKER_COLORSQUARE_H

#include <iostream>
#include "Box.h"
#include "GUIComponents.h"
#include "MouseEvents.h"

class ColorSquare: public sf::Drawable {
private:
    Box square;
    bool isClicked;
public:
    ColorSquare();
    void setColor(sf::Color color);
    void setOutLineColor(sf::Color color);
    void setSize(float x, float y);
    void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Rect<float> getGlobalBounds();
    bool clicked() const;
    sf::Color getColor();
    void reset();
};


#endif //LOGOMAKER_COLORSQUARE_H
