#ifndef FILETREE_TEXTURE_H
#define FILETREE_TEXTURE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Texture{
private:
    static sf::Texture texture;
    static void loadTexture(std::string str);

public:
    static sf::Texture& getTexture(std::string str);
};


#endif //FILETREE_TEXTURE_H
