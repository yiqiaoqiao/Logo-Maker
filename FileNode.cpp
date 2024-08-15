#include "FileNode.h"

void FileNode::reposition() const{
    sf::FloatRect rectB = data.getGlobalBounds();
    if(!children.empty())
        children.at(0)->setPosition(rectB.left+50, rectB.top+rectB.height);
    if(children.size() > 1) {
        for (int i = 1; i < children.size(); i++) {
            sf::FloatRect childB = children.at(i-1)->getGlobalBounds();
            children.at(i)->setPosition(rectB.left + 50,
                                        childB.top+childB.height);
        }
    }
}

void FileNode::toggleChlidren() {
    if(data.checkState(HIDDEN)) {
        //std::cout << "Change to NOT Hidden" << std::endl;
        data.disableState(HIDDEN);
    }
    else
        data.enableState(HIDDEN);
}

FileNode::FileNode() {
    //states.enableState(HIDDEN);
    //click = false;
    data.enableState(HIDDEN);
    enableState(HIDDEN);
    isClicked = false;
    s = "";
}

FileNode::FileNode(std::string fileName, std::string text) {
    //reposition();
    data.setIcon(fileName);
    data.setText(text);
    //states.enableState(HIDDEN);
    //click = false;
    data.enableState(HIDDEN);
    enableState(HIDDEN);
    isClicked = false;
    s = "";
}

FileNode::FileNode(bool isFile, std::string text) {
    //reposition();
    data.setIcon(isFile);
    data.setText(text);
    //states.enableState(HIDDEN);
    //click = false;
    data.enableState(HIDDEN);
    enableState(HIDDEN);
    isClicked = false;
    s = "";
}

FileNode &FileNode::operator=(const FileNode &RHS) {
    if(this == &RHS){
        return *this;
    }
    data = RHS.data;
    children.clear();
    for(int i = 0; i < RHS.children.size(); i++){
        children.push_back(RHS.children[i]);
    }
    data.enableState(HIDDEN);
    enableState(HIDDEN);
    isClicked = RHS.isClicked;
    s = RHS.s;
    return *this;
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    reposition();
    window.draw(data);
    if(!checkState(HIDDEN)){
        //If not hidden, draw the children
        //std::cout << "Not Hidden" << std::endl;
        for(int i = 0; i < children.size(); i++){
            //Draw the children
            children.at(i)->draw(window, states);
        }
    }
}

void FileNode::applySnapshot(const Snapshot &snapshot) {
    //Not currently used
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //data.addEventHandler(window, event);
    if(MouseEvents::mouseClicked(*this, window)){
        //std::cout << data.getString() << " clicked" << std::endl;
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        //std::cout << "Set children to black" << std::endl;

        for(int i = 0; i < children.size(); i++)
            children.at(i)->setColor("black");

        if(data.isInObject(mousePos.x, mousePos.y) && !checkState(HIDDEN)){
            //Click on the data again, then hide the children
            //toggleChlidren();
            enableState(HIDDEN);
            isClicked = false;
            //data.setColor("black");
        }
        else if (isInObject(mousePos.x, mousePos.y) && checkState(HIDDEN)){
            toggleChlidren();
            disableState(HIDDEN);
            data.setColor("blue");
            if(children.empty()){
                s = data.getString();
                isClicked = true;
            }
        }
        else
            data.setColor("black");
    }

}

void FileNode::update() {
    //Does nothing now
}

Snapshot& FileNode::getSnapshot() {
    //Does nothing now
    Snapshot s;
    return s;
}

sf::FloatRect FileNode::getGlobalBounds() {
    sf::FloatRect bound = data.getGlobalBounds();
    if(!checkState(HIDDEN)){
        for(int i = 0; i < children.size(); i++){
            bound.height += children.at(i)->getGlobalBounds().height;
        }
    }
    return bound;
}

bool FileNode::isLeaf() const {
    if(children.empty())
        return true;
    return false;
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::vector<FileNode *> &FileNode::getChildren() {
    return children;
}

void FileNode::addChild(const FileItem &item) {
    auto* temp = new FileNode;
    temp->data = item;
    children.push_back(temp);
    //std::cout << "size: " << children.size() << std::endl;
    reposition();
}

void FileNode::addChild(FileNode* node) {
    children.push_back(node);
    //reposition();
}


typename std::vector<FileNode*>::iterator FileNode::begin(){
    std::vector<FileNode*>::iterator ptr = children.begin();
    return ptr;
}

typename std::vector<FileNode*>::iterator FileNode::end(){
    std::vector<FileNode*>::iterator ptr = children.end();
    return ptr;
}

void FileNode::setPosition(float x, float y) {
    data.setPosition(x,y);
    //reposition();
}

bool FileNode::isInObject(float x, float y) {
    /*
    sf::FloatRect bounds = data.getGlobalBounds();
    if(x >= bounds.left  && x <= bounds.left+bounds.width){
        if(y >= bounds.top  && y <= bounds.top+bounds.height)
            return true;
    }
    return false;
     */

    //If it is in children's object, return true
    for(int i = 0; i < children.size(); i++){
        if(children.at(i)->isInObject(x,y))
            return true;
    }
    //If it is in data's object, return true
    sf::FloatRect bounds = data.getGlobalBounds();
    if(x >= bounds.left  && x <= bounds.left+bounds.width){
        if(y >= bounds.top  && y <= bounds.top+bounds.height)
            return true;
    }
    return false;
}

void FileNode::setColor(std::string color) {
    data.setColor(color);
    for(int i = 0; i < children.size(); i++)
        children.at(i)->setColor(color);
}

bool FileNode::clicked() {
    return isClicked;
}

std::string FileNode::getDataText() {
    return s;
}

void FileNode::reset() {
    isClicked = false;
    s = "";
    for(int i = 0; i < children.size(); i++)
        children.at(i)->setColor("black");
}

