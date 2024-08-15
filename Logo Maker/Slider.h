#ifndef LOGOMAKER_SLIDER_H
#define LOGOMAKER_SLIDER_H

#include "Box.h"
#include "Text.h"
#include "GUIComponents.h"
#include "MouseEvents.h"
#include "History.h"
#include <iostream>
#include <cmath>

class Slider: public GUIComponents{
private:
    Text text;
    Box bar;
    sf::CircleShape dot;
    Text number;
    int n;
    Snapshot snapshot;
    int i;
    int prevN;
    bool addSnapshot;
public:
    Slider();
    void setBarSize(float x, float y);
    void setBarPosition(float x, float y);
    void setDotRadius(float r);
    void setDotPosition(float x, float y);
    void setText(std::string s);
    void setNumber(std::string s);
    void setTextSize(int s);
    void setPosition(float x, float y);
    void setDotCenter(float x, float y);
    sf::Rect<float> getGlobalBounds();
    sf::Rect<float> dragGlobalBounds();
    sf::Rect<float> getBarGlobalBounds();
    sf::Rect<float> getTextGlobalBounds();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    int getN();
    void setN(int n);
    void reset();
    void setDot(int p);
    void setI(int i);
    bool shouldApply();
    void resetSnapshotState();
};


#endif //LOGOMAKER_SLIDER_H
