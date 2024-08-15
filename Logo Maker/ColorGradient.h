#ifndef LOGOMAKER_COLORGRADIENT_H
#define LOGOMAKER_COLORGRADIENT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GUIComponents.h"
#include "MouseEvents.h"

class ColorGradient: public GUIComponents{
private:
    sf::VertexArray gradient;
    int size;
    sf::Color choseColor;
public:
    ColorGradient();
    void setPosition(float x, float y);
    void setColor(int hue);
    void setColor(sf::Color c);
    int findHue(sf::Color c);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Rect<float> getGlobalBounds();
    sf::Color getChoseColor();
    void reset();
    void setChoseColor(sf::Color c);
};


#endif //LOGOMAKER_COLORGRADIENT_H
