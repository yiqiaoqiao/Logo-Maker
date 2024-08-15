#ifndef FILETREE_FILENODE_H
#define FILETREE_FILENODE_H

#include <iostream>
#include <vector>
#include <iterator>
#include "FileItem.h"
#include "GUIComponents.h"

class FileNode: public GUIComponents{
private:
    FileItem data;
    std::vector<FileNode*> children;
    //States states;
    //bool click;
    //this is called in the draw function to reposition the children so they
    //are indented and below the parent
    void reposition() const;
    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();
    bool isClicked;
    std::string s;
public:
    // this is so I can use the iterator for the children vector publicly
    typedef std::vector<FileNode*>::iterator iterator;
    FileNode();
    FileNode(std::string fileName, std::string text);
    FileNode(bool isFile, std::string text);
    FileNode& operator =(const FileNode& RHS);

    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //This is not currently used
    virtual void applySnapshot(const Snapshot& snapshot);

    //This calls the addEventHandler for all the children. It changed the states when item is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    //does nothing now
    sf::FloatRect getGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    std::vector<FileNode*>& getChildren();
    void addChild(const FileItem &item);
    void addChild(FileNode* node);
    void setPosition(float x, float y);
    bool isInObject(float x, float y);
    void setColor(std::string color);
    bool clicked();
    std::string getDataText();
    void reset();

    //iterators
    iterator begin();
    iterator end();

};


#endif //FILETREE_FILENODE_H
