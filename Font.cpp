#include "Font.h"

sf::Font Font::font;

void Font::loadFont() {
    if (!font.loadFromFile("Roboto Bold.ttf")){
        std::cout<<"Font Class(): Font failed to load"<<std::endl;
        exit(-1);
    }
}

sf::Font &Font::getFont() {
    loadFont();
    return font;
}

void Font::loadFont(std::string s) {
    if (!font.loadFromFile(s)){
        std::cout<<"Font Class(std::string): Font failed to load"<<std::endl;
        exit(-1);
    }
}

sf::Font &Font::getFont(std::string s) {
    loadFont(s);
    return font;
}
