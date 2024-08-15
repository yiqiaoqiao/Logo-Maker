#ifndef LOGOMAKER_SLIDERLIST_H
#define LOGOMAKER_SLIDERLIST_H

#include "Slider.h"
#include "History.h"
#include <iostream>
#include <vector>

class SliderList: public GUIComponents {
private:
    std::vector<Slider> list;
    Snapshot snapshot;
public:
    SliderList();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Vector2f getTextPosition();
    sf::Vector2f getShadowPosition();
    int getFontSize();
    int getTextOpacity();
    int getShadowOpacity();
    int getBackgroundOpacity();
    float getSkew();
    void reset();
    void setTextPosition(sf::Vector2f pos);
    void setShadowPosition(sf::Vector2f pos);
    void setFontSize(int s);
    void setTextOpacity(int s);
    void setShadowOpacity(int s);
    void setBackgroundOpacity(int s);
    void setSkew(float s);
};


#endif //LOGOMAKER_SLIDERLIST_H
