#ifndef PROJECT1_MOUSEEVENTS_H
#define PROJECT1_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>
#include <iostream>

class MouseEvents {
public:
    // returns true if the mouse clicks on the object
    template <class T>
    static bool mouseClicked(T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked(sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    // returns true if the object has been clicked and the mouse has dragged over the object
    template <class T>
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse is hovered over the object
    template <class T>
    static bool hovered(T& object, sf::RenderWindow& window);

    static void resetClick();

private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
    static sf::Clock clock;
    static int clicks;
    static float mousePosX;
    static float mousePosY;
    static void countClicks(sf::Event event);
};

template<class T>
bool MouseEvents::mouseClicked(T &object, sf::RenderWindow &window) {
    //std::cout << "click: " << clicks << std::endl;
    /*
    if(clicks>0){
        if(object.isInObject(mousePosX, mousePosY))
            return true;
    }
    return false;
     */
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect bound = object.getGlobalBounds();
    return (bound.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

template<class T>
bool MouseEvents::hovered(T &object, sf::RenderWindow &window) {
    sf::FloatRect bound = object.getGlobalBounds();
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return bound.contains(mousePos);
    /*
    float x = sf::Mouse::getPosition(window).x;
    float y = sf::Mouse::getPosition(window).y;
    if(object.isInObject(x,y))
        return true;
    return false;
     */
}

template<class T>
bool MouseEvents::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect bound = object.dragGlobalBounds();
    return (bound.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == sf::Event::MouseMoved);
}

//#include "MouseEvents.cpp"

#endif //PROJECT1_MOUSEEVENTS_H
