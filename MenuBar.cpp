#include "MenuBar.h"

MenuBar::MenuBar() {
    //Input box: black with white text
    //List items: black with white text
    Menu menu1;
    menu1.setInputBoxText("File");
    menu1.addItem("Close Project");
    menu1.addItem("New Project");
    menu1.addItem("Open Project");
    menu1.addItem("Quit");
    menu1.addItem("Save Project");
    menu1.setListSize(400, 80);
    menu1.setListTextSize(30);
    menu1.setListColor("black");
    menu1.setListTextColor("white");
    menu1.setMenuPosition(0,0);
    menu1.setInputBoxSize(200, 80);
    menu1.setInputBoxColor("black");
    menu1.setInputBoxTextColor("white");
    menu1.setInputBoxTextSize(30);
    //std::cout << "size: " << menuList.getSize() << std::endl;
    menuList.insertHead(menu1);
    //std::cout << "Here" << std::endl;

    Menu menu2;
    menu2.setInputBoxText("Edit");
    menu2.addItem("Redo");
    menu2.addItem("Undo");
    menu2.setListSize(400, 80);
    menu2.setListTextSize(30);
    menu2.setListColor("black");
    menu2.setListTextColor("white");
    menu2.setMenuPosition(menuList.findPos(0).getInputBoxSize().x,0);
    menu2.setInputBoxSize(200, 80);
    menu2.setInputBoxColor("black");
    menu2.setInputBoxTextColor("white");
    menu2.setInputBoxTextSize(30);
    menuList.insertTail(menu2);

    Menu menu3;
    menu3.setInputBoxText("Render");
    menu3.addItem("Export Image");
    menu3.setListSize(400, 80);
    menu3.setListTextSize(30);
    menu3.setListColor("black");
    menu3.setListTextColor("white");
    menu3.setMenuPosition(menuList.findPos(0).getInputBoxSize().x*2,0);
    menu3.setInputBoxSize(200, 80);
    menu3.setInputBoxColor("black");
    menu3.setInputBoxTextColor("white");
    menu3.setInputBoxTextSize(30);
    menuList.insertTail(menu3);

    hoveredMenu = -1;
}

void MenuBar::setPosition(float x, float y) {
    float tempX = x;
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        (*iter).setMenuPosition(x,y);
        tempX += (*iter).getInputBoxSize().x;
    }
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    //std::cout << "Draw " << std::endl;
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        //std::cout << "Iter Color: " << (*iter).getBoxColor() << std::endl;
        window.draw(*iter);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        (*iter).addEventHandler(window, event);
    }
}

void MenuBar::update() {
    //MouseEvents::resetClick();
    /*
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        (*iter).update();
    }
     */
}

bool MenuBar::isInObject(float x, float y){
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        if((*iter).isInObject(x,y))
            return true;
    }
    return false;
}

void MenuBar::enableListState(ObjectStates state) {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        (*iter).enableStates(state);
    }
}

int MenuBar::findMouseClickedMenu(float x, float y) {
    int count = 0;
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        if((*iter).isInInputBox(x,y))
            return count;
        count++;
    }
    return -1;
}

bool MenuBar::isInList(float x, float y) {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        if((*iter).isInList(x,y))
            return true;
    }
    return false;
}

bool MenuBar::isInInputBox(float x, float y) {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        if((*iter).isInInputBox(x,y)) {
            //std::cout << "Is in Input Box" << std::endl;
            return true;
        }
    }
    return false;
}

void MenuBar::disableOneMenuState(int pos, ObjectStates state) {
    LinkedList<Menu>::iterator iter = menuList.begin();
    for(int i = 0; i < pos; i++)
        ++iter;
    (*iter).disableStates(state);
}

void MenuBar::resetAllColor(std::string color) {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        (*iter).setListColor(color);
        (*iter).setInputBoxColor(color);
    }
}

bool MenuBar::checkOneMenuState(int pos, ObjectStates state) {
    LinkedList<Menu>::iterator iter = menuList.begin();
    for(int i = 0; i < pos; i++)
        ++iter;
    return (*iter).checkState(state);
}

void MenuBar::setOneMenuInputBoxColor(int pos, std::string color) {
    LinkedList<Menu>::iterator iter = menuList.begin();
    for(int i = 0; i < pos; i++)
        ++iter;
    (*iter).setInputBoxColor(color);
}

bool MenuBar::isInList(int pos, float x, float y) {
    if(pos == -1)
        return false;
    LinkedList<Menu>::iterator iter = menuList.begin();
    for(int i = 0; i < pos; i++)
        ++iter;
    if((*iter).isInList(x,y))
        return true;
    return false;
}

Snapshot &MenuBar::getSnapshot() {
    //DO NOTHING
}

void MenuBar::applySnapshot(const Snapshot &snapshot) {
    //DO NOTHING
}

sf::Rect<float> MenuBar::getGlobalBounds() {
    LinkedList<Menu>::iterator iter = menuList.begin();
    sf::Rect<float> bounds = (*iter).getInputBoxGlobalBounds();
    bounds.width *= menuList.getSize();
    return bounds;
}

void MenuBar::resetMenu() {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        (*iter).resetMenu();
    }
}

std::string MenuBar::getChosenMenu() {
    int count = 0;
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        if((*iter).isClicked()) {
            //std::cout << (*iter).getInputBoxName() << std::endl;
            //std::cout << (*iter).getChosenMenu() << std::endl;
            return (*iter).getChosenMenu();
        }
        count++;
    }
    return "";
}

bool MenuBar::isClicked() {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        if((*iter).isClicked())
            return true;
    }
    return false;
}

void MenuBar::setAllListHidden() {
    LinkedList<Menu>::iterator iter;
    for(iter = menuList.begin(); iter != menuList.end(); ++iter) {
        (*iter).enableStates(HIDDEN);
    }
}


