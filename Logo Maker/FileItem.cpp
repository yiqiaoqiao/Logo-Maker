#include "FileItem.h"

FileItem::FileItem() {
    box.setColor("black");
    text.setColor("white");
    text.setString("Directory 1");
    box.setSize(350, 100);
    box.setPosition(0,0);
    reAdjustSize();
    reAdjustPosition();
    enableState(HIDDEN);
    isFile = false;
}

FileItem::FileItem(bool isFile, std::string text) {
    /*
    if(isFile)
        std::cout << "File" << std::endl;
    else
        std::cout << "Directory" << std::endl;
        */
    box.setColor("black");
    this->text.setColor("white");
    icon.setImage(isFile);
    this->text.setString(text);
    box.setSize(300, 100);
    box.setPosition(0,0);
    reAdjustSize();
    reAdjustPosition();
    enableState(HIDDEN);
    //std::cout << "Text Character size: " << this->text.getCharacterSize() << std::endl;
    //box.setBorderThickness(5);
    //box.setBorderColor("yellow");
    this->isFile = isFile;
}

FileItem::FileItem(std::string fileName, std::string text) {
    box.setColor("black");
    this->text.setColor("white");
    icon.setImage(fileName);
    this->text.setString(text);
    box.setSize(300, 100);
    box.setPosition(0,0);
    reAdjustSize();
    reAdjustPosition();
    enableState(HIDDEN);
}

FileItem &FileItem::operator=(const FileItem &RHS) {
    if(this == &RHS){
        return *this;
    }
    icon = RHS.icon;
    box = RHS.box;
    text = RHS.text;
    return *this;
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(text);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //If it is clicked, turn blue, else black
    if(MouseEvents::mouseClicked(*this, window)) {
        box.setColor("blue");
        //disableState(HIDDEN);
    }
    else{
        box.setColor("black");
        //enableState(HIDDEN);
    }
}

void FileItem::setIcon(const Icon& i) {
    icon = i;
}

void FileItem::setIcon(bool isFile) {
    isFile = isFile;
    icon.setImage(isFile);
}

void FileItem::setIcon(std::string str) {
    icon.setImage(str);
}

void FileItem::setPosition(float x, float y) {
    box.setPosition(x,y);
    //std::cout << "Set Position" << std::endl;
    reAdjustPosition();
    //std::cout << "Text Character size: " << text.getCharacterSize() << std::endl;
}

void FileItem::setSize(float x, float y) {
    box.setSize(x,y);
    reAdjustSize();
    //reAdjustPosition();
}

sf::FloatRect FileItem::getGlobalBounds() const{
    return box.getGlobalBound();
}

sf::Vector2f FileItem::getSize(){
    return box.getSize();
}

sf::Vector2f FileItem::getPosition(){
    return box.getPosition();
}

bool FileItem::isInObject(float x, float y) {
    //std::cout << "Check is in object" << std::endl;
    sf::FloatRect rectB = box.getGlobalBound();
    //std::cout << rectB.left << ", " << rectB.top << std::endl;
    if(x >= rectB.left && x <= rectB.left+rectB.width){
        if(y >= rectB.top && y <= rectB.top+rectB.height){
            //std::cout << "Is in Object" << std::endl;
            return true;
        }
    }
    return false;
}

void FileItem::reAdjustPosition() {
    sf::FloatRect rectB = box.getGlobalBound();
    sf::FloatRect textB = text.getGlobalBound();
    sf::FloatRect iconB = icon.getGlobalBound();

    //Set icon to the 1/3 left of the box
    rectB.width /= 3;
    icon.setPosition(
            rectB.left + (rectB.width / 2) - (iconB.width / 2),
            rectB.top + (rectB.height / 2) - (iconB.height/2));

    //Set the text next to the icon
    rectB = box.getGlobalBound();
    rectB.left += rectB.width/3;
    rectB.width = rectB.width*2/3;
    text.setPosition(rectB.left + 10,rectB.top + (rectB.height / 2) - textB.height);
}

void FileItem::reAdjustSize() {
    //std::cout << "readjust size: " << std::endl;
    sf::FloatRect rectB = box.getGlobalBound();
    //Icon size adjust to the left 1/3 of the box
    rectB.width /= 3;
    icon.reAdjustScale(rectB);

    //Text size adjust to the right 2/3 of the box;
    //std::cout << "size: " << text.getCharacterSize() << std::endl;
    rectB = box.getGlobalBound();
    rectB.left += rectB.width/3;
    rectB.width = rectB.width*2/3;
    text.reAdjustSize(rectB);
}

void FileItem::setText(std::string str) {
    text.setString(str);
}


std::string FileItem::getString() {
    return text.getString();
}

void FileItem::applySnapshot(const Snapshot &snapshot) {
    //DO nothing
}

void FileItem::update() {
    //Do nothing
}

Snapshot &FileItem::getSnapshot() {
    //DO NOTHING
}

void FileItem::setColor(std::string color) {
    box.setColor(color);
}

bool FileItem::file() {
    return isFile;
}



