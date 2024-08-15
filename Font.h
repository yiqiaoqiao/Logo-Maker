#ifndef DROPDOWNMENU_FONT_H
#define DROPDOWNMENU_FONT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Font {
private:
    static sf::Font font;
    static void loadFont();
    static void loadFont(std::string s);
public:
    static sf::Font& getFont();
    static sf::Font& getFont(std::string s);
};


#endif //DROPDOWNMENU_FONT_H
