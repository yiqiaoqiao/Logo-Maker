#ifndef FILETREE_FILETREE_H
#define FILETREE_FILETREE_H

#include <iostream>
#include "FileNode.h"

class FileTree: public GUIComponents{
private:
    //the root node of the tree
    FileNode* root = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item, bool isFile);

    //traverses the tree ad adds the event handlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    sf::Vector2f initPosition = {0, 0};

public:
    //constructors
    FileTree();

    //this is the public version of push
    void push(std::string parent, std::string item = "NULL", bool isFile = false);

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    //does nothing now
    virtual sf::FloatRect getGlobalBounds();

    std::string clickedItem();
    void reset();
};


#endif //FILETREE_FILETREE_H
