#include "Menu.h"

Menu::Menu() {
    states.enableState(HIDDEN);
    //hoveredPos = -1;
    //clickPos = -1;
    pos = -1;
}

Menu::Menu(const Menu &RHS) {
    list = RHS.list;
    inputBox = RHS.inputBox;
    states = RHS.states;
    pos = RHS.pos;
}

Menu &Menu::operator=(const Menu &RHS) {
    if(this == &RHS){
        return *this;
    }
    list = RHS.list;
    inputBox = RHS.inputBox;
    pos = RHS.pos;
    return *this;
}

bool Menu::isInObject(float mousePosX, float mousePosY) {
    if(isInInputBox(mousePosX, mousePosY) || isInList(mousePosX, mousePosY))
        return true;
    return false;
}

bool Menu::isInInputBox(float mousePosX, float mousePosY) {
    if(mousePosX > (inputBox.getPosition().x-inputBox.getBoxBorderThickness())
       && mousePosX < (inputBox.getPosition().x+inputBox.getSize().x+inputBox.getBoxBorderThickness())){
        if(mousePosY > (inputBox.getPosition().y-inputBox.getBoxBorderThickness())
           && (mousePosY < inputBox.getPosition().y+inputBox.getSize().y+inputBox.getBoxBorderThickness()))
            return true;
    }
    return false;
}

bool Menu::isInList(float mousePosX, float mousePosY) {
    //std::cout << inputBox.getText() << " is in list" << std::endl;
    return list.isInList(mousePosX, mousePosY);
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!this->states.checkState(HIDDEN)){
        //std::cout << "Draw list" << std::endl;
        window.draw(list);
    }
    window.draw(inputBox);
}

void Menu::setMenuPosition(float x, float y) {
    inputBox.setBoxPosition(x,y);
    list.setPosition(inputBox.getPosition().x-inputBox.getBoxBorderThickness(),
                     inputBox.getPosition().y+inputBox.getSize().y+inputBox.getBoxBorderThickness());
}

void Menu::setMenuSize(float x, float y) {
    inputBox.setBoxSize(x,y);
    list.setPosition(inputBox.getPosition().x-inputBox.getBoxBorderThickness(),
                     inputBox.getPosition().y+inputBox.getSize().y+inputBox.getBoxBorderThickness());
    list.setSize(inputBox.getSize().x+inputBox.getBoxBorderThickness(), inputBox.getSize().y);
}

void Menu::setInputBoxColor(std::string color) {
    inputBox.setBoxColor(color);
}

void Menu::setListSize(float x, float y) {
    list.setSize(x, y);
}

void Menu::addItem(std::string s) {
    list.addItem(s);
}

void Menu::setListTextSize(int s) {
    list.setTextSize(s);
}

void Menu::setListColor(std::string color) {
    list.setBoxColor(color);
}

void Menu::setListTextColor(std::string color) {
    list.setTextColor(color);
}

void Menu::setInputBoxText(std::string s) {
    inputBox.setText(s);
}

void Menu::setInputBoxTextSize(int s) {
    inputBox.setTextSize(s);
}

void Menu::setInputBoxTextColor(std::string color) {
    inputBox.setTextColor(color);
}

void Menu::setInputBoxSize(float x, float y) {
    inputBox.setBoxSize(x,y);
}

sf::Vector2f Menu::getInputBoxSize() {
    return inputBox.getSize();
}

void Menu::enableStates(ObjectStates state) {
    //std::cout << "state enabled" << std::endl;
    states.enableState(state);
}

void Menu::disableStates(ObjectStates state) {
    //std::cout << "state disabled" << std::endl;
    states.disableState(state);
}

/*
void Menu::setHoveredPos(int p) {
    hoveredPos = p;
}

int Menu::getHoveredPos() {
    return hoveredPos;
}

void Menu::setHoveredColor(float x, float y, std::string color) {
    int p = list.getPositionFromMouse(y);
    //std::cout << "P: " << p << std::endl;
    if(p<list.getLinkedListSize()){
        if(p != hoveredPos) {
            list.setBoxColor("black");
            list.setOneBoxColor(p, color);
            hoveredPos = p;
        }
    }
}
 */

bool Menu::checkState(ObjectStates state) {
    return states.checkState(state);
}


sf::Rect<float> Menu::getGlobalBounds() {
    sf::Rect<float> bound = inputBox.getGlobalBounds();
    bound.height += list.getGlobalBounds().height;
    bound.width = list.getGlobalBounds().width;
    return bound;
}

sf::Rect<float> Menu::getInputBoxGlobalBounds() {
    return inputBox.getGlobalBounds();
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(MouseEvents::mouseClicked(window, event)){
        if(!isInInputBox(mousePos.x, mousePos.y) && !isInList(mousePos.x, mousePos.y)){
            //Not in list or Input Box
            states.enableState(HIDDEN);
            inputBox.setBoxColor(sf::Color::Black);
            list.setBoxColor(sf::Color::Black);
        }
        else if(isInInputBox(mousePos.x, mousePos.y)){
            //Click on the input box
            states.disableState(HIDDEN);
            inputBox.setBoxColor(sf::Color::Blue);
            list.setBoxColor(sf::Color::Black);
        }
        else if(isInList(mousePos.x, mousePos.y)){
            //std::cout << "Clicked" << std::endl;
            if(!states.checkState(HIDDEN)) {
                pos = list.getPositionFromMouse(mousePos.x, mousePos.y);
                //std::cout << getOneBoxText(pos) << std::endl;
            }
        }
    }
    else if(MouseEvents::hovered(*this, window)){
        if(!isInInputBox(mousePos.x, mousePos.y) && !isInList(mousePos.x, mousePos.y)){
            inputBox.setBoxColor(sf::Color::Black);
            list.setBoxColor(sf::Color::Black);
        }
        else if(isInInputBox(mousePos.x, mousePos.y)){
            inputBox.setBoxColor(sf::Color::Blue);
        }
        else if(isInList(mousePos.x, mousePos.y)){
            setListColor(sf::Color::Black);
            int i = list.getPositionFromMouse(mousePos.x, mousePos.y);
            setOneBoxColor(i, sf::Color::Blue);
        }
    }
    else{
        if(states.checkState(HIDDEN))
            inputBox.setBoxColor(sf::Color::Black);
        list.setBoxColor(sf::Color::Black);
    }
}

void Menu::update() {
    //DO NOTHING
}

Snapshot &Menu::getSnapshot() {
    //DO NOTHING
}

void Menu::applySnapshot(const Snapshot &snapshot) {
    //DO NOTHING
}

void Menu::setListColor(sf::Color c) {
    list.setBoxColor(c);
}

void Menu::setOneBoxColor(int i,sf::Color c) {
    list.setOneBoxColor(i, c);
}

void Menu::setListTextColor(sf::Color c) {
    list.setTextColor(c);
}

void Menu::setInputBoxTextColor(sf::Color c) {
    inputBox.setTextColor(c);
}

void Menu::setInputBoxBorderThickness(float c) {
    inputBox.setBoxBorderThickness(c);
}

void Menu::setInputBoxBorderColor(sf::Color c) {
    inputBox.setBoxBorderColor(c);
}

void Menu::setInputBoxColor(sf::Color c) {
    inputBox.setBoxColor(c);
}

int Menu::getPositionFromMouse(float x, float y) {
    return list.getPositionFromMouse(x,y);
}

void Menu::toggleState() {
    if(states.checkState(HIDDEN))
        states.disableState(HIDDEN);
    else
        states.enableState(HIDDEN);
}

std::string Menu::getOneBoxText(int i) {
    return list.getOneBoxText(i);
}

void Menu::resetMenu() {
    pos = -1;
}

std::string Menu::getChosenMenu() {
    if(pos != -1)
        return getOneBoxText(pos);
    return  "";
}

bool Menu::isClicked() {
    if(pos == -1)
        return false;
    return true;
}

std::string Menu::getInputBoxName() {
    return inputBox.getText();
}


