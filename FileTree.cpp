#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, std::string item, bool isFile) {
    if(root->getData().getString() == parent){
        //Push the item into the child of this root
        //bool isFile = false;
        FileItem item1(isFile, item);
        root->addChild(item1);
    }
    else{
        //Go through the children list and find the parent and push the item
        for(int i = 0; i < root->getChildren().size(); i++){
            push(root->getChildren().at(i), parent, item, isFile);
        }
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
    for(int i = 0; i < root->getChildren().size(); i++){
        traverse(root->getChildren().at(i), window, event);
    }
}

FileTree::FileTree() {
    root = nullptr;
}

void FileTree::push(std::string parent, std::string item, bool isFile) {
    if(root == nullptr){
        root = new FileNode;
        FileItem item1(false, parent);
        root->setData(item1);

        //Push the item to the parent child
        push(root, parent, item, isFile);
    }
    else {
        //std::cout << "push" << std::endl;
        push(root, parent, item, isFile);
    }
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    root->draw(window, states);
    /*
    for(int i = 0; i < root->getChildren().size(); i++){
        root->getChildren().at(i)->draw(window, states);
    }
     */
}

void FileTree::applySnapshot(const Snapshot &snapshot) {
    //does nothing now
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    traverse(root, window, event);
}

void FileTree::update() {
    //does nothing now
}

Snapshot &FileTree::getSnapshot() {
    //does nothing now
    Snapshot s;
    return s;
}

sf::FloatRect FileTree::getGlobalBounds() {
    if(root != nullptr)
        return root->getGlobalBounds();
    return sf::FloatRect();
}

std::string FileTree::clickedItem() {
    std::string s = "";
    if(root->clicked()){
        return root->getDataText();
    }
    for(int i = 0; i < root->getChildren().size(); i++){
        //Go through children and get data text
        if(root->getChildren().at(i)->clicked())
            return root->getChildren().at(i)->getDataText();
    }
    return s;
}

void FileTree::reset() {
    root->reset();
    for(int i = 0; i < root->getChildren().size(); i++){
        //Go through children and get data text
        root->getChildren().at(i)->reset();
    }
}

