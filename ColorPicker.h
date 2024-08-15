#ifndef LOGOMAKER_COLORPICKER_H
#define LOGOMAKER_COLORPICKER_H

#include <iostream>
#include "ColorList.h"
#include "ColorGradient.h"
#include "Text.h"
#include "History.h"

class ColorPicker: public GUIComponents{
private:
    ColorList list;
    ColorSquare square;
    Text text;
    ColorGradient gradient;
    sf::Color c;
    sf::Color gradientC;
    Snapshot snapshot;
    bool textColor;
public:
    ColorPicker();
    ColorPicker(sf::Color c);
    void setTextPosition(float x, float y);
    void setSquareColor(sf::Color c);
    void setPosition(float x, float y);
    void setText(std::string s);
    sf::Rect<float> getGlobalBounds();
    bool isInList();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Color getColor();
    sf::Color getListColor();
    void reset();
    void setColor(sf::Color c, sf::Color gc);
    void setTextColor(bool s);
};


#endif //LOGOMAKER_COLORPICKER_H
