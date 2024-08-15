#ifndef LOGOMAKER_WINDOW_H
#define LOGOMAKER_WINDOW_H

#include "FileTree.h"
#include "Item.h"
#include "GUIComponents.h"

class Window{
private:
    FileTree fileTree;
    Item open;
    Item cancel;
    std::string filePath;
    sf::RenderWindow window;
public:
    Window();
    void runWindow();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    std::string getFilePath();
    void addFilePath(std::string s);
};


#endif //LOGOMAKER_WINDOW_H
