#ifndef PROJECT1_GUICOMPONENTS_H
#define PROJECT1_GUICOMPONENTS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SnapshotInterface.h"
#include "EventHandler.h"
#include "States.h"

class GUIComponents: public sf::Drawable,
                     public sf::Transformable,
                     public EventHandler,
                     public SnapshotInterface,
                     public States{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //PROJECT1_GUICOMPONENTS_H
