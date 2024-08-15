#include "ItemList.h"

ItemList::ItemList() {
    //Do Nothing
}

ItemList &ItemList::operator=(const ItemList &RHS) {
    if(this == &RHS){
        return *this;
    }
    list.clear();
    list.copyList(RHS.list);
    return *this;
}

void ItemList::addItem(std::string itemName) {
    Item item = Item(itemName);
    //std::cout << "Item Name: " << itemName << std::endl;
    sf::Vector2f newPos = newPosition();
    item.setBoxPosition(newPos.x, newPos.y);
    list.insertTail(item);
}

void ItemList::setPosition(float x, float y) {
    float xTemp = x, yTemp = y;
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setBoxPosition(xTemp, yTemp);
        yTemp += (*iter).getBoxSize().y;
    }
}

void ItemList::setSize(float x, float y) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setBoxSize(x,y);
    }
    adjustPosition();
}

void ItemList::setTextSize(int size) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setTextSize(size);
    }
}

void ItemList::setBoxColor(std::string color) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setBoxColor(color);
    }
}

void ItemList::setTextColor(std::string color) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setTextColor(color);
    }
}

void ItemList::setBoxBorderThickness(float size) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setBoxBorderThickness(size);
    }
    adjustPosition();
}

void ItemList::setBoxBorderColor(std::string color) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setBoxBorderColor(color);
    }
}

void ItemList::setOneBoxColor(int pos, std::string color) {
    //std::cout << "setOneBoxColor: set " << pos << " to color: " << color << std::endl;
    LinkedList<Item>::iterator iter = list.begin();
    for(int i = 0; i < pos; i++)
        ++iter;
    (*iter).setBoxColor(color);
}

void ItemList::adjustPosition() {
    sf::Vector2f pos = list.findPos(0).getBoxPosition();
    float outline = list.findPos(0).getBoxBorderThickness();
    float y = list.findPos(0).getBoxSize().y;
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setBoxPosition(pos.x, pos.y);
        pos.y += 2*outline+y;
    }
}

sf::Vector2f ItemList::newPosition() {
    //If size = 0 then set the position to 0,0
    if(list.getSize() == 0)
        return {0,0};
    else{
        sf::Vector2f lastPosition = list.findPos(list.getSize()-1).getBoxPosition();
        //Add the vertical (y) size of the rectangle box
        lastPosition.y += list.findPos(list.getSize()-1).getBoxSize().y;
        return lastPosition;
    }
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        //std::cout << "Iter Color: " << (*iter).getBoxColor() << std::endl;
        window.draw(*iter);
    }
}

Item ItemList::getItem(int pos) {
    assert(pos < list.getSize());
    return list.findPos(pos);
}

sf::Vector2f ItemList::getInitPos() {
    return list.findPos(0).getBoxPosition();
}

sf::Vector2f ItemList::getListSize() {
    sf::Vector2f size = list.findPos(0).getBoxSize();
    size.y *= (float)list.getSize();
    return size;
}

/*
std::string ItemList::getPositionText(float mouseY) {
    //Only check y position because x position is fixed
    int temp = getPositionFromMouse(mouseY);
    return list.findPos(temp).getTextString();
}
 */

int ItemList::getPositionFromMouse(float x, float y) {
    sf::Vector2f pos(x,y);
    LinkedList<Item>::iterator iter;
    int count = 0;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        sf::Rect<float> bounds = (*iter).getGlobalBounds();
        if(bounds.contains(pos))
            return count;
        count++;
    }
    return -1;
}

/*
void ItemList::setPositionColor(float mouseY, std::string c) {
    //std::cout << "Get position Color" << std::endl;
    //setBoxColor("blue");
    int temp = getPositionFromMouse(mouseY);
    //std::cout << "ItemList color: " << c << std::endl;
    //std::cout << "temp: " << temp << std::endl;
    if(temp < list.getSize()) {
        setOneBoxColor(temp, c);
        //std::cout << list.findPos(temp).getBoxColor() << std::endl;
    }
}
 */

int ItemList::getLinkedListSize() {
    return list.getSize();
}

sf::Rect<float> ItemList::getGlobalBounds() {
    sf::Rect<float> bound;
    if(list.getSize() > 0){
        LinkedList<Item>::iterator iter = list.begin();
        bound = (*iter).getGlobalBounds();
        bound.height *= list.getSize();
    }
    return bound;
}

void ItemList::setBoxColor(sf::Color color) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setBoxColor(color);
    }
}

bool ItemList::isInList(float x, float y) {
    sf::Vector2f pos(x,y);
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        sf::Rect<float> bounds = (*iter).getGlobalBounds();
        if(bounds.contains(pos))
            return true;
    }
    return false;
}

void ItemList::setOneBoxColor(int pos, sf::Color color) {
    LinkedList<Item>::iterator iter = list.begin();
    for(int i = 0; i < pos; i++)
        ++iter;
    (*iter).setBoxColor(color);
}

void ItemList::setTextColor(sf::Color color) {
    LinkedList<Item>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setTextColor(color);
    }
}

std::string ItemList::getOneBoxText(int i) {
    LinkedList<Item>::iterator iter = list.begin();
    for(int j = 0; j < i; j++)
        ++iter;
    return (*iter).getTextString();
}



