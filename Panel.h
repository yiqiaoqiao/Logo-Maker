#ifndef LOGOMAKER_PANEL_H
#define LOGOMAKER_PANEL_H

#include "Text.h"
#include "Box.h"

class Panel: public sf::Drawable{
private:
    Text text;
    Text shadow;
    Box panel;
    sf::Font font;
    std::string fontName;
public:
    Panel();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setText(std::string s);
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setBackgroundColor(sf::Color c);
    void setTextMiddle();
    void setFontSize(int size);
    void setTextColor(sf::Color c);
    void setFont(std::string s);
    void setTextPosition(float x, float y);
    void setOpacity(int t, int s, int b);
    void setSkew(float n);
    sf::Rect<float> getGlobalBound();
    void setShadowPosition(float x, float y);
    std::string getString();
    sf::Color getTextColor();
    sf::Color getBackgroundColor();
    std::string getFontName();
    sf::Vector2f getTextPosition();
    int getFontSize();
    int getTextOpacity();
    int getShadowOpacity();
    int getBackgroundOpacity();
    float getSkew();
    sf::Vector2f getShadowPosition();
    sf::Text getText();
    sf::Text getShadow();
    sf::RectangleShape getPanel();
};


#endif //LOGOMAKER_PANEL_H
