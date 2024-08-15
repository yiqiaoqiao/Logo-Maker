#ifndef PROJECT1_EVENTHANDLER_H
#define PROJECT1_EVENTHANDLER_H

#include "States.h"
#include "ObjectStates.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class EventHandler{
private:
    States states;
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //PROJECT1_EVENTHANDLER_H
