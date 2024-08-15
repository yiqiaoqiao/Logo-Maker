#include "Letter.h"

Letter::Letter(std::string s): str(s), charSize(50), x(310), y(92){
    //font = f;
    text.setFont(Font::getFont());
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::White);
    text.setPosition(sf::Vector2f(x,y));
    text.setString(str);
}

/*
Letter& Letter::operator= (const Letter& l){
    if (!font.loadFromFile("Deiland.ttf")){
        std::cout<<"Sidebar() CTOR: Font failed to load"<<std::endl;
        std::cin.get();
        exit(-1);
    }
    text.setFont(font);
    str = l.str;
    text.setString(str);
    charSize = l.charSize;
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::White);
    x = l.x;
    y = l.y;
    text.setPosition(sf::Vector2f(x,y));
}
 */

sf::Text Letter::getText(){
    return text;
}
std::string Letter::getString(){
    return str;
}
void Letter::addCh(char ch){
    str += ch;
}
void Letter::addStr(std::string s){
    str += s;
}
void Letter::setStr(std::string s) {
    str = s;
    text.setString(s);
}
/*
void Letter::setFont(sf::Font f){
    font = f;
}
 */
void Letter::setCharacterSize(int size){
    text.setCharacterSize(size);
}
void Letter::setStyle(std::string s){
    if(s == "B")
        text.setStyle(sf::Text::Bold);
    else if(s == "I")
        text.setStyle(sf::Text::Italic);
    else if(s == "U")
        text.setStyle(sf::Text::Underlined);
    else if(s == "S")
        text.setStyle(sf::Text::StrikeThrough);
}
void Letter::setColor(sf::Color color){
    text.setColor(color);
}
void Letter::setPos(float x, float y){
    this->x = x;
    this->y = y;
    text.setPosition(sf::Vector2f(x, y));
}

int Letter::getCharacterSize(){
    return charSize;
}

void Letter::printPos(){
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
void Letter::getPos(float& x, float& y){
    x = this->x;
    y = this->y;
}

char Letter::getChar() {
    return str[0];
}

float Letter::getWidth() {
    return text.getGlobalBounds().width+10;
}

Letter &Letter::operator=(const Letter &RHS) {
    if(this == &RHS){
        return *this;
    }
    x = RHS.x;
    y = RHS.y;
    charSize = RHS.charSize;
    str = RHS.str;
    text = RHS.text;
    return *this;
}

/*
void Letter::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    std::cout << "pos: (" << x << ", " << y << ")" << std::endl;
    window.draw(text);
}
*/
