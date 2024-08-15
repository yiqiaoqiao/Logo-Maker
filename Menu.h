#ifndef MENUBAR_MENU_H
#define MENUBAR_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ItemList.h"
#include "InputBox.h"
#include "MouseEvents.h"

class Menu: public GUIComponents{
private:
    ItemList list;
    InputBox inputBox;
    States states;
    int pos;
public:
    Menu();
    Menu(const Menu& RHS);
    Menu& operator =(const Menu& RHS);
    bool isInObject(float mousePosX, float mousePosY);
    bool isInInputBox(float mousePosX, float mousePosY);
    bool isInList(float mousePosX, float mousePosY);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    void setMenuPosition(float x, float y);
    void setMenuSize(float x, float y);
    int getPositionFromMouse(float x, float y);

    void setListSize(float x, float y);
    void addItem(std::string s);
    void setListTextSize(int s);
    void setListColor(std::string color);
    void setListTextColor(std::string color);
    void setListTextColor(sf::Color c);
    void setListColor(sf::Color c);
    void setOneBoxColor(int i, sf::Color c);

    void setInputBoxColor(std::string color);
    void setInputBoxColor(sf::Color c);
    void setInputBoxText(std::string s);
    void setInputBoxTextSize(int s);
    void setInputBoxTextColor(std::string color);
    void setInputBoxTextColor(sf::Color c);
    void setInputBoxSize(float x, float y);
    void setInputBoxBorderThickness(float c);
    void setInputBoxBorderColor(sf::Color c);

    void enableStates(ObjectStates state);
    void disableStates(ObjectStates state);
    void toggleState();
    //void setHoveredPos(int p);
    //int getHoveredPos();
    //void setHoveredColor(float x, float y, std::string color);
    bool checkState(ObjectStates state);
    sf::Vector2f getInputBoxSize();
    sf::Rect<float> getGlobalBounds();
    sf::Rect<float> getInputBoxGlobalBounds();
    std::string getOneBoxText(int i);
    void resetMenu();
    std::string getChosenMenu();
    bool isClicked();
    std::string getInputBoxName();
};


#endif //MENUBAR_MENU_H
