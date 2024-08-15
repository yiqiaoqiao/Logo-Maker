#ifndef DROPDOWNMENU_ITEMLIST_H
#define DROPDOWNMENU_ITEMLIST_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>
#include "Item.h"
#include "LinkedList.h"

class ItemList: public sf::Drawable{
private:
    LinkedList<Item> list;
public:
    ItemList();
    ItemList& operator =(const ItemList& RHS);
    void addItem(std::string itemName);
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void setTextSize(int size);
    void setBoxColor(std::string color);
    void setBoxColor(sf::Color color);
    void setTextColor(std::string color);
    void setTextColor(sf::Color color);
    void setBoxBorderThickness(float size);
    void setBoxBorderColor(std::string color);
    void setOneBoxColor(int pos, std::string color);
    void setOneBoxColor(int pos, sf::Color color);
    bool isInList(float x, float y);
    //std::string getPositionText(float mouseY);
    int getPositionFromMouse(float x, float y);
    //void setPositionColor(float mouseY, std::string c);
    void adjustPosition();
    sf::Vector2f newPosition();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Item getItem(int pos);
    sf::Vector2f getInitPos();
    sf::Vector2f getListSize();
    int getLinkedListSize();
    sf::Rect<float> getGlobalBounds();
    std::string getOneBoxText(int i);
};


#endif //DROPDOWNMENU_ITEMLIST_H
