#ifndef LOGOMAKER_LOGOMAKER_H
#define LOGOMAKER_LOGOMAKER_H

#include "GUIComponents.h"
#include "TextInput.h"
#include "MenuBar.h"
#include "Panel.h"
#include "SliderList.h"
#include "ColorPicker.h"
#include "FontList.h"
#include "Window.h"
#include <fstream>

class LogoMaker: public GUIComponents{
private:
    Box botRect;
    Box topRect;
    TextInput textInput;
    MenuBar menuBar;
    Panel panel;
    SliderList sliderList;
    ColorPicker fontPicker;
    ColorPicker backgroundPicker;
    FontList fontList;
    sf::Sprite sprite;
    sf::RenderTexture texture;
    sf::Image image;
    std::string filePath;
    Snapshot snapshot;
    Window window;
    //bool isChanging;
public:
    LogoMaker();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    void updatePanel();
    void menuBarChoice(sf::RenderWindow &window);
    void exportImage();
    void reset();
    void writeOutput();
    void updateTexture();
    void setLogoMaker(std::string filePath);
};

#endif //LOGOMAKER_LOGOMAKER_H
