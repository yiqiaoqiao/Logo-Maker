#ifndef FILETREE_FILEITEM_H
#define FILETREE_FILEITEM_H

#include "Icon.h"
#include "Box.h"
#include "Text.h"
#include "MouseEvents.h"
#include "GUIComponents.h"
#include <iostream>
#include <SFML/Graphics.hpp>

//A file item includes rectangle, and on the rect there is an icon and a text
class FileItem: public GUIComponents{
private:
    Icon icon;
    Box box;
    Text text;
    bool isFile;
public:
    FileItem();
    FileItem(bool isFile, std::string text);
    FileItem(std::string fileName, std::string text);
    FileItem& operator =(const FileItem& RHS);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //This is not currently used
    virtual void applySnapshot(const Snapshot& snapshot);
    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    void setIcon(const Icon& i);
    void setIcon(bool isFile);
    void setIcon(std::string str);
    void setText(std::string str);
    void setPosition(float x, float y);
    void setSize(float x, float y);
    void reAdjustPosition();
    void reAdjustSize();
    bool isInObject(float x, float y);
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getSize();
    sf::Vector2f getPosition();
    std::string getString();
    void setColor(std::string color);
    bool file();
};


#endif //FILETREE_FILEITEM_H
