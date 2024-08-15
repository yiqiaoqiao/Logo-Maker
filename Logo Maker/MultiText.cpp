#include "MultiText.h"

MultiText::MultiText(): x(310), y(90){
    /*
    if (!font.loadFromFile("Deiland.ttf")){
        std::cout<<"Sidebar() CTOR: Font failed to load"<<std::endl;
        std::cin.get();
        exit(-1);
    }
     */
}
void MultiText::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    LinkedList<Letter>::iterator iter;
    //std::cout << (*iter).getString() << std::endl;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        //Letter t((*iter).getString());
        //std::cout << "Here" << std::endl;
        //Letter l = *iter;
        //std::cout << "data: " << (*iter).getString() << std::endl;
        sf::Text t = (*iter).getText();
        t.setFont(Font::getFont());
        //std::cout << t.getPosition().x << t.getPosition().y << std::endl;
        window.draw(t);
    }
}
void MultiText::addText(std::string s){
    Letter l(s);
    l.setPos(x,y);
    l.setCharacterSize(characterSize);
    x+=l.getWidth();
    //l.printPos();
    list.insertTail(l);
    //setSetting();
}

void MultiText::pop(){
    x-=lastLetterWidth();
    list.removePos(list.getSize()-1);
}

bool MultiText::empty() const {
    return list.isEmpty();
}

/*
void MultiText::setSetting(){
    //std::cout << "Size: " << list.getSize() << std::endl;
    int charSize = (int)(height-20) / list.getSize();
    float x = 10, y = 10;
    for(int i = 0; i < list.getSize(); i++) {
        if(charSize < 50)
            //list.at(i).setCharacterSize(charSize);
        //list.at(i).setPos(x,y);
        y += (float)charSize;
    }
}
 */

Node_iterator<struct Letter> MultiText::begin() const {
    LinkedList<Letter>::iterator iter = list.begin();
    return iter;
}

Node_iterator<struct Letter> MultiText::end() const {
    LinkedList<Letter>::iterator iter = list.end();
    return iter;
}

void MultiText::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
    LinkedList<Letter>::iterator iter;
    for(iter = list.begin(); iter != list.end(); ++iter) {
        (*iter).setPos(x,y);
        x+=(*iter).getWidth();
    }
}

float MultiText::lastLetterWidth() {
    //std::cout << list.getSize() << std::endl;
    if(list.getSize() == 0)
        return 0;
    LinkedList<Letter>::iterator iter = list.begin();
    for(int j = 0; j < list.getSize()-1; j++){
        ++iter;
    }
    return (*iter).getWidth();
}

int MultiText::size() {
    return list.getSize();
}

MultiText& MultiText::operator=(const MultiText &RHS) {
    //std::cout << "MultiText Operator = " << std::endl;
    if(this == &RHS){
        return *this;
    }
    //list.clear();
    //std::cout << "Here" << std::endl;
    list = RHS.list;
    //std::cout << "Here" << std::endl;
    x = RHS.x;
    y = RHS.y;
    setPosition(x,y);
    /*
    if (!font.loadFromFile("Deiland.ttf")){
        std::cout<<"Sidebar() CTOR: Font failed to load"<<std::endl;
        std::cin.get();
        exit(-1);
    }
     */
    return *this;
}

MultiText::MultiText(const MultiText &RHS) {
    x = RHS.x;
    y = RHS.y;
    list = RHS.list;
}

void MultiText::copyMultiText(const MultiText &RHS) {
    //std::cout << "Copy MultiText" << std::endl;
    x = RHS.x;
    y = RHS.y;
    list = RHS.list;
}

float MultiText::lastLetterXPos() const {
    return x;
}

LinkedList<Letter> MultiText::getList() {
    return list;
}

void MultiText::changeToWhite() {
    for(int i = 0; i < list.getSize(); i++){
        changeColor(sf::Color::White, i);
    }
}

void MultiText::changeToBlack(){
    for(int i = 0; i < list.getSize(); i++){
        changeColor(sf::Color::Black, i);
    }
}

void MultiText::adjustColor() {
    changeToWhite();
    for (int i = 0; i < list.getSize(); i++) {
        char ch = list.findPos(i).getChar();
        if (std::toupper(ch) == 'I') {
            //Check int
            if ((i + 2) < list.getSize()) {
                if (std::toupper(list.findPos(i + 1).getChar()) == 'N'
                    && std::toupper(list.findPos(i + 2).getChar()) == 'T') {
                    //Is int
                    //std::cout << "Is Int" << std::endl;
                    changeColor(sf::Color::Blue, i);
                    changeColor(sf::Color::Blue, i+1);
                    changeColor(sf::Color::Blue, i+2);
                }
            }
        }
        else if (std::toupper(ch) == 'D') {
            //Check double
            if ((i + 5) < list.getSize()) {
                if (std::toupper(list.findPos(i + 1).getChar()) == 'O'
                    && std::toupper(list.findPos(i + 2).getChar()) == 'U'
                    && std::toupper(list.findPos(i + 3).getChar()) == 'B'
                    && std::toupper(list.findPos(i + 4).getChar()) == 'L'
                    && std::toupper(list.findPos(i + 5).getChar()) == 'E') {
                    //Is double
                    //std::cout << "Is Double" << std::endl;
                    changeColor(sf::Color::Blue, i);
                    changeColor(sf::Color::Blue, i+1);
                    changeColor(sf::Color::Blue, i+2);
                    changeColor(sf::Color::Blue, i+3);
                    changeColor(sf::Color::Blue, i+4);
                    changeColor(sf::Color::Blue, i+5);
                }
            }
        }
        else if (std::toupper(ch) == 'F') {
            //Check float
            if ((i + 4) < list.getSize()) {
                if (std::toupper(list.findPos(i + 1).getChar()) == 'L'
                    && std::toupper(list.findPos(i + 2).getChar()) == 'O'
                    && std::toupper(list.findPos(i + 3).getChar()) == 'A'
                    && std::toupper(list.findPos(i + 4).getChar()) == 'T') {
                    //Is float
                    //std::cout << "Is Float" << std::endl;
                    changeColor(sf::Color::Blue, i);
                    changeColor(sf::Color::Blue, i+1);
                    changeColor(sf::Color::Blue, i+2);
                    changeColor(sf::Color::Blue, i+3);
                    changeColor(sf::Color::Blue, i+4);
                }
            }
        }
        else if (std::toupper(ch) == 'C') {
            //Check char
            if ((i + 3) < list.getSize()) {
                if (std::toupper(list.findPos(i + 1).getChar()) == 'H'
                    && std::toupper(list.findPos(i + 2).getChar()) == 'A'
                    && std::toupper(list.findPos(i + 3).getChar()) == 'R') {
                    //Is char
                    //std::cout << "Is Char" << std::endl;
                    changeColor(sf::Color::Blue, i);
                    changeColor(sf::Color::Blue, i+1);
                    changeColor(sf::Color::Blue, i+2);
                    changeColor(sf::Color::Blue, i+3);
                }
            }
        }
        else if (std::isdigit(ch)) {
            //Is Number
            //std::cout << "Is Number" << std::endl;
            changeColor(sf::Color::Red, i);
        }
        else if ((int(ch) >= 33 && int(ch) <= 64) || (int(ch) >= 91 && int(ch) <= 96) ||
                 (int(ch) >= 123 && int(ch) <= 126)) {
             // Is Operator: see ascii table
             //33-64 !"#$%&'()*+,-./
             //91-96 :;<=>?@
             //123-126 {|}~
            //std::cout << "Is Operator" << std::endl;
            changeColor(sf::Color::Green, i);
        }
    }
}

void MultiText::changeColor(sf::Color color, int i) {
    LinkedList<Letter>::iterator iter = list.begin();
    for(int j = 0; j < i; j++){
        ++iter;
    }
    (*iter).setColor(color);
}

void MultiText::setLetterSize(int size) {
    characterSize = size;
}

std::string MultiText::getString() {
    std::string s = "";
    LinkedList<Letter>::iterator iter = list.begin();
    for(int i = 0; i < list.getSize(); i++){
        s += (*iter).getString();
        ++iter;
    }
    return s;
}

void MultiText::clear() {
    list.clear();
}
