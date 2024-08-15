#include "FontList.h"

FontList::FontList() {
    fontList.addItem("Roboto Bold");
    fontList.addItem("Arial");
    fontList.addItem("Arcade");
    fontList.addItem("Open Sans Bold");
    fontList.setInputBoxText("Roboto Bold");
    setPosition(0,0);
    setSize(500, 80);
    setInputBoxColor(sf::Color::Black);
    setTextColor(sf::Color::White);
    setInputBoxBorderColor(sf::Color::White);
    setInputBoxBorderThickness(2);
    setTextSize(35);
    choseText = "Roboto Bold";
}

void FontList::setPosition(float x, float y) {
    fontList.setMenuPosition(x,y);
}

void FontList::setSize(float x, float y) {
    fontList.setInputBoxSize(x,y);
    fontList.setListSize(x,y);
}

void FontList::setInputBoxColor(sf::Color c) {
    fontList.setInputBoxColor(c);
}

void FontList::setInputBoxBorderColor(sf::Color c) {
    fontList.setInputBoxBorderColor(c);
}

void FontList::setInputBoxBorderThickness(float s) {
    fontList.setInputBoxBorderThickness(s);
}

void FontList::setTextColor(sf::Color c) {
    fontList.setListTextColor(c);
    fontList.setInputBoxTextColor(c);
}

void FontList::setListColor(sf::Color c) {
    fontList.setListColor(c);
}

void FontList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(fontList);
}

void FontList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    snapshot = getSnapshot();
    snapshot.setFontName(getText());
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(MouseEvents::mouseClicked(window, event)){
        //std::cout << "Clicked" << std::endl;
        if(!fontList.isInInputBox(mousePos.x, mousePos.y) && !fontList.isInList(mousePos.x, mousePos.y)){
            //std::cout << "Clicked" << std::endl;
            //Not in list or Input Box
            fontList.enableStates(HIDDEN);
        }
        else if(fontList.isInInputBox(mousePos.x, mousePos.y)){
            //Click on the input box
            //std::cout << "Clicked on Input Box" << std::endl;
            fontList.toggleState();
        }
        else if(!fontList.checkState(HIDDEN)){
            if(fontList.isInList(mousePos.x, mousePos.y)){
                //std::cout << "Is In List" << std::endl;
                //std::cout << "Clicked on List" << std::endl;
                setListColor(sf::Color::Black);
                int i = fontList.getPositionFromMouse(mousePos.x, mousePos.y);
                fontList.setOneBoxColor(i, sf::Color::Blue);
                choseText = fontList.getOneBoxText(i);
                fontList.setInputBoxText(choseText);
                //std::cout << "push: " << snapshot.getFontName() << std::endl;
                History::pushHistory({snapshot, this});
            }
        }
    }
    else if(MouseEvents::hovered(*this, window)){
        //std::cout << "Hovered" << std::endl;
        if(!fontList.isInList(mousePos.x, mousePos.y)){
            fontList.setListColor(sf::Color::Black);
        }
        else if(fontList.isInList(mousePos.x, mousePos.y)){
            setListColor(sf::Color::Black);
            int i = fontList.getPositionFromMouse(mousePos.x, mousePos.y);
            fontList.setOneBoxColor(i, sf::Color::Blue);
        }
    }
}

void FontList::update() {
    //DO NOTHING
    //std::cout << "Text: " << choseText << std::endl;
}

Snapshot &FontList::getSnapshot() {
    return snapshot;
}

void FontList::applySnapshot(const Snapshot &snapshot) {
    this->snapshot = snapshot;
    setChoseText(snapshot.getFontName());
}

void FontList::setTextSize(int s) {
    fontList.setListTextSize(s);
    fontList.setInputBoxTextSize(s);
}

bool FontList::isInInputBox(float x, float y) {
    return fontList.isInInputBox(x,y);
}

bool FontList::isInList(float x, float y) {
    return fontList.isInList(x,y);
}

sf::Rect<float> FontList::getGlobalBounds() {
    return fontList.getGlobalBounds();
}

std::string FontList::getText() {
    return choseText;
}

void FontList::reset() {
    choseText = "Roboto Bold";
    fontList.setInputBoxText(choseText);
}

void FontList::setChoseText(std::string c) {
    choseText = c;
    fontList.setInputBoxText(choseText);
}
