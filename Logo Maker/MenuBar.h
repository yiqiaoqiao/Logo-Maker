#ifndef MENUBAR_MENUBAR_H
#define MENUBAR_MENUBAR_H

#include "Menu.h"
#include "LinkedList.h"
#include "GUIComponents.h"
#include "MouseEvents.h"

class MenuBar: public GUIComponents {
private:
    LinkedList<Menu> menuList;
    int hoveredMenu;

public:
    MenuBar();
    void setPosition(float x, float y);
    bool isInObject(float x, float y);
    bool isInInputBox(float x, float y);
    bool isInList(float x, float y);
    bool isInList(int pos, float x, float y);
    void enableListState(ObjectStates state);
    void disableOneMenuState(int pos, ObjectStates state);
    int findMouseClickedMenu(float x, float y);
    void resetAllColor(std::string color);
    void setOneMenuInputBoxColor(int pos, std::string color);
    bool checkOneMenuState(int pos, ObjectStates state);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
    sf::Rect<float> getGlobalBounds();
    void resetMenu();
    std::string getChosenMenu();
    bool isClicked();
    void setAllListHidden();
};


#endif //MENUBAR_MENUBAR_H
