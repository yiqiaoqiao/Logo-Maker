#include "ColorPicker.h"

ColorPicker::ColorPicker() {
    text.setString("");
    text.setCharacterSize(30);
    text.setPosition(0,0);
    text.setColor(sf::Color::White);
    square.setPosition(0,0);
    square.setColor(sf::Color::Red);
    square.setOutLineColor(sf::Color::White);
    list.setPosition(100,0);
    list.enableState(HIDDEN);
    gradient.enableState(HIDDEN);
    c = sf::Color::Red;
    gradientC = sf::Color::Red;
    textColor = false;
}

ColorPicker::ColorPicker(sf::Color c) {
    text.setString("");
    text.setCharacterSize(30);
    text.setPosition(0,0);
    text.setColor(sf::Color::White);
    square.setPosition(0,0);
    square.setColor(c);
    list.setPosition(100,0);
    list.enableState(HIDDEN);
    gradient.enableState(HIDDEN);
    textColor = false;
}

void ColorPicker::setTextPosition(float x, float y) {
    text.setPosition(x,y);
}

void ColorPicker::setSquareColor(sf::Color c) {
    square.setColor(c);
    list.setChoseColor(c);
}

void ColorPicker::setPosition(float x, float y) {
    square.setPosition(x,y);
    list.setPosition(x, y+square.getGlobalBounds().height);
    gradient.setPosition(x, y+square.getGlobalBounds().height);
}

void ColorPicker::setText(std::string s) {
    text.setString(s);
}

sf::Rect<float> ColorPicker::getGlobalBounds() {
    return square.getGlobalBounds();
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
    window.draw(square);
    window.draw(list);
    window.draw(gradient);
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    snapshot = getSnapshot();
    if(textColor){
        snapshot.setTextColor(getColor());
        snapshot.setTextListColor(getListColor());
    }
    else {
        snapshot.setBackgroundColor(getColor());
        snapshot.setBackgroundListColor(getListColor());
    }

    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect listB = list.getGlobalBounds();
    sf::FloatRect gradientB = gradient.getGlobalBounds();
    if(MouseEvents::mouseClicked(*this, window)){
        //Click on the color square, show the list
        //std::cout << "Show panel" << std::endl;
        list.disableState(HIDDEN);
        gradient.enableState(HIDDEN);
    }
    else if(MouseEvents::mouseClicked(window, event)){
        if(!list.checkState(HIDDEN) && listB.contains(mousePos)){
            //Click on the list
            list.addEventHandler(window, event);
        }
        else if(!gradient.checkState(HIDDEN)&& gradientB.contains(mousePos)){
            //Click on the gradient box
            //std::cout << "Show Gradient" << std::endl;
            gradient.addEventHandler(window, event);
        }
        else{
            //Click on others, hide all
            gradient.enableState(HIDDEN);
            list.enableState(HIDDEN);
        }
    }
}

void ColorPicker::update() {
    //Set the color that the user choose to gradient
    if(!list.checkState(HIDDEN)){
        list.update();
        if(list.getClickedColor() != c) {
            //User click on some other color on the color list
            c = list.getClickedColor();
            gradient.setColor(c);
            //History::pushHistory({snapshot, this});
            list.enableState(HIDDEN);
            gradient.disableState(HIDDEN);
        }
    }
    else if(!gradient.checkState(HIDDEN)){
        //std::cout << "Gradient color: " << std::endl;
        if(gradient.getChoseColor() != gradientC){
            gradientC = gradient.getChoseColor();
            //std::cout << "push to history" << std::endl;
            History::pushHistory({snapshot, this});
            square.setColor(gradientC);
        }
    }
}

Snapshot &ColorPicker::getSnapshot() {
    return snapshot;
}

void ColorPicker::applySnapshot(const Snapshot &snapshot) {
    this->snapshot = snapshot;
    if(textColor){
        setColor(snapshot.getTextListColor(), snapshot.getTextColor());
    }
    else
        setColor(snapshot.getBackgroundListColor(), snapshot.getBackgroundColor());
}

sf::Color ColorPicker::getColor() {
    return gradientC;
}

void ColorPicker::reset() {
    square.setColor(sf::Color::Red);
    c = sf::Color::Red;
    gradientC = sf::Color::Red;
    //gradient.setColor(sf::Color::Red);
    list.reset();
    gradient.reset();
    //list.enableState(HIDDEN);
    //gradient.enableState(HIDDEN);
}

void ColorPicker::setColor(sf::Color c, sf::Color gc) {
    gradientC = gc;
    this->c = c;
    square.setColor(gc);
    list.setChoseColor(c);
    gradient.setChoseColor(gc);
}

sf::Color ColorPicker::getListColor() {
    return c;
}

void ColorPicker::setTextColor(bool s) {
    textColor = s;
}
