#include <iostream>
#include <SFML/Graphics.hpp>
#include "LogoMaker.h"

int main() {
    sf::RenderWindow window({2500, 1500}, "Logo Maker");
    window.setFramerateLimit(60);
    LogoMaker logoMaker;
    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            logoMaker.addEventHandler(window, event);
        }
        logoMaker.update();
        window.clear(sf::Color::Black);
        window.draw(logoMaker);
        window.display();
    }
    return 0;
}
