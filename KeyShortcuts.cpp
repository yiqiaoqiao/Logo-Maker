#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo() {
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
       || (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))){
        //Undo key: Control + Z
        return true;
    }
    return false;
}
