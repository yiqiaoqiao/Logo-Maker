#ifndef FILETREE_IMAGE_H
#define FILETREE_IMAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Image {
private:
    static sf::Image image;
    static void loadImage(std::string str);

public:
    static sf::Image& getImage(std::string str);
};


#endif //FILETREE_IMAGE_H
