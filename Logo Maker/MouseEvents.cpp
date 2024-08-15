//#ifndef PROJECT1_MOUSEEVENTS_CPP
//#define PROJECT1_MOUSEEVENTS_CPP

#include "MouseEvents.h"

sf::Clock MouseEvents::clock;
int MouseEvents::clicks = 0;
float MouseEvents::mousePosX = 0;
float MouseEvents::mousePosY = 0;

bool MouseEvents::mouseClicked(sf::RenderWindow& window, sf::Event event){
    if(event.type == sf::Event::MouseButtonPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
    }
    return false;
}

bool MouseEvents::mouseDoubleClicked(){
    //countClicks()
    if(clicks==2)
        return true;
    return false;
}

bool MouseEvents::mouseTripleClicked(){
    if(clicks==3)
        return true;
    return false;
}

void MouseEvents::countClicks(sf::Event event){
    if(event.type == sf::Event::MouseButtonPressed){
        mousePosX = event.mouseButton.x;
        mousePosY = event.mouseButton.y;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(clicks==0)
                clicks++;
            else if(clicks==3)
                clicks = 1;
            else{
                float sec = clock.getElapsedTime().asSeconds();
                if(sec < 1.0){
                    clicks++;
                }
                else{
                    clicks = 1;
                }
            }
            clock.restart();
        }
    }
}

void MouseEvents::resetClick() {
    clicks = 0;
}

//#endif //PROJECT1_MOUSEEVENTS_CPP