#include "TextInput.h"

TextInput::TextInput() {
    //Name
    //label.setFont(Font::getFont());
    label.setString("Name:");
    label.setColor("white");
    label.setCharacterSize(info.labelSize);
    label.setPosition(info.labelPos.x, info.labelPos.y);

    //Input Box
    inputBox.setSize(info.inboxSize.x, info.inboxSize.y);
    inputBox.setPosition(info.inboxPos.x, info.inboxPos.y);
    inputBox.setColor("black");
    inputBox.setBorderColor("white");
    inputBox.setBorderThickness(2);

    //Cursor
    cursor.setSize(info.cursorSize.x, info.cursorSize.y);
    cursor.setPosition(info.cursorPos.x, info.cursorPos.y);
    cursor.setColor("white");

    //Others
    inInputBox = false;
    count = 0;
    cursorXPos = info.cursorPos.x;
}

void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(inputBox);
    window.draw(label);
    if(inInputBox){
        //states=getTransform();
        if(!this->states.checkState(HIDDEN)) {
            //std::cout << "Cursor not hidden" << std::endl;
            window.draw(cursor);
        }
    }
    if(!multiText.empty())
        window.draw(multiText);
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event){
    //std::cout << "Event Handler" << std::endl;
    //History::addEventHandler(window, event);
    snapshot = getSnapshot();
    snapshot.setText(getString());
    if(event.type == sf::Event::TextEntered){
        //std::cout << "Keyboard" << std::endl;
        if(inInputBox){
            //std::cout << "Key pressed" << std::endl;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
            {
                //std::cout << "Size: " << multiText.size() << std::endl;
                if(!multiText.empty()) {
                    cursorXPos-=multiText.lastLetterWidth();
                    multiText.pop();
                    cursor.setPosition(cursorXPos, info.cursorPos.y);

                    History::pushHistory({snapshot, this});

                    //std::cout << "Add to History" << std::endl;
                }
            }
            else{
                //Input is a letter
                if(canAddLetter()){
                    std::string s;
                    s += static_cast<char>(event.text.unicode);
                    multiText.addText(s);
                    //std::cout << "Add Size: " << multiText.size() << std::endl;
                    //std::cout << "Size: " << multiText.size() << std::endl;
                    cursorXPos+=multiText.lastLetterWidth();
                    if(canAddLetter()){
                        cursor.setPosition(cursorXPos, info.cursorPos.y);
                    }
                    else{
                        cursorXPos-=multiText.lastLetterWidth();
                        multiText.pop();
                    }

                    History::pushHistory({snapshot, this});

                    //std::cout << "Add to History" << std::endl;
                }
            }
        }
    }
    //std::cout << "Mouse Clicked" << std::endl
    else if(MouseEvents::mouseClicked(window, event)){
        //std::cout << "Mouse Clicked" << std::endl;
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if(isInInputBox(mousePos.x, mousePos.y)) {
            //std::cout << "Click on Input box" << std::endl;
            inInputBox = true;
        }
        else {
            //std::cout << "Click on Other" << std::endl;
            inInputBox = false;
        }
    }
}

void TextInput::update(){
    //applySnapshot(getSnapshot());
    if(inInputBox){
        //std::cout << "Cursor Blinks" << std::endl;
        count++;
        if(count == 30){
            if(!states.checkState(HIDDEN))
                states.enableState(HIDDEN);
            else
                states.disableState(HIDDEN);
            count = 0;
        }
    }
    else {
        //std::cout << "Hidden Cursor" << std::endl;
        states.enableState(HIDDEN);
    }
    //multiText.adjustColor();
}

bool TextInput::canAddLetter() const{
    if(multiText.lastLetterXPos() >= info.inboxPos.x+info.inboxSize.x){
        return false;
    }
    return true;
}

Snapshot &TextInput::getSnapshot() {
    return snapshot;
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    //std::cout << "Apply Snapshot" << std::endl;
    //std::cout << "CursorXPos: " << cursorXPos << std::endl;
    //std::cout << "Here" << std::endl;
    this->snapshot = snapshot;
    setText(snapshot.getText());
    //cursor.setPosition(cursorXPos, info.cursorPos.y);
}

bool TextInput::isInObject(float x, float y) const{
    //std::cout << "(" << x << ", " << y << ")" << std::endl;
    return isInInputBox(x,y);
}

bool TextInput::isInInputBox(float x, float y) const {
    if(x > info.inboxPos.x && x < info.inboxPos.x+info.inboxSize.x){
        if(y > info.inboxPos.y && y < info.inboxPos.y+info.inboxSize.y)
            return true;
    }
    return false;
}

void TextInput::setLabel(const std::string& str) {
    label.setString(str);
}

void TextInput::setLabelSize(int s) {
    label.setCharacterSize(s);
}

void TextInput::setLabelMargin(float t, float b, float l, float r) {
    float size = label.getGlobalBound().width;
    info.labelPos.y += t;
    info.labelPos.x += l;
    //assert(label.getGlobalBounds().height+t+b+info.labelPos.y<info.buttonPos.y);
    label.setPosition(info.labelPos.x, info.labelPos.y);
    //std::cout << "Size: " << size << std::endl;
    info.inboxPos.x = label.getPosition().x+size+30+l+r;
    inputBox.setPosition(info.inboxPos.x, info.inboxPos.y);
    //std::cout << "Inbox position: " << info.inboxPos.x << ", " << info.inboxPos.y << std::endl;
    if(info.inboxPos.x+info.inboxSize.x > info.width){
        //Shrink the size of the input box
        info.inboxSize.x = info.width - 30 - info.inboxPos.x;
        inputBox.setSize(info.inboxSize.x, info.inboxSize.y);
    }

    //Change cursor position
    info.cursorPos.x = info.inboxPos.x+10;
    cursor.setPosition(info.cursorPos.x, info.cursorPos.y);
    cursorXPos = info.cursorPos.x;
    multiText.setPosition(info.cursorPos.x, info.cursorPos.y);
}

void TextInput::setPosition(float x, float y) {
    //assert(label.getGlobalBounds().height+y<info.buttonPos.y);
    //assert(inputBox.getGlobalBound().width+x<info.width);
    info.labelPos.x = x;
    info.labelPos.y = y;
    label.setPosition(info.labelPos.x, info.labelPos.y);
    sf::Rect<float> labelBounds = label.getGlobalBound();
    //std::cout << "Label height: " << labelBounds.height << std::endl;
    //std::cout << "Label text size: " << label.getCharacterSize() << std::endl;

    //Set input box position below the label
    info.inboxPos.x = x;
    info.inboxPos.y = labelBounds.top + labelBounds.height + 10;
    inputBox.setPosition(info.inboxPos.x, info.inboxPos.y);

    //Change cursor position
    info.cursorPos.x = info.inboxPos.x+10;
    info.cursorPos.y = info.inboxPos.y;
    cursor.setPosition(info.cursorPos.x, info.cursorPos.y);
    cursorXPos = info.cursorPos.x;
    multiText.setPosition(info.cursorPos.x, info.cursorPos.y);
}

void TextInput::setSize(float x, float y) {
    info.inboxSize = sf::Vector2f(x,y);
    inputBox.setSize(info.inboxSize.x, info.inboxSize.y);
}

sf::Rect<float> TextInput::getGlobalBounds() {
    return inputBox.getGlobalBound();
}

void TextInput::setBorderColor(std::string color) {
    inputBox.setBorderColor(color);
}

void TextInput::setBoxColor(std::string color) {
    inputBox.setBorderColor(color);
    if(color == "black")
        cursor.setColor("white");
    else if(color == "white")
        cursor.setColor("black");
}

void TextInput::setBorderSize(float size) {
    inputBox.setBorderThickness(size);
}

void TextInput::setLetterSize(int s) {
    multiText.setLetterSize(s);
}

std::string TextInput::getString() {
    return multiText.getString();
}

void TextInput::reset() {
    while (!multiText.empty()){
        cursorXPos-=multiText.lastLetterWidth();
        multiText.pop();
        cursor.setPosition(cursorXPos, info.cursorPos.y);
    }
}

void TextInput::check() {
    std::string text = History::topHistory().snapshot.getText();
    std::string str = getString();
    //std::cout << "text: " << text << std::endl;
    //std::cout << "str: " << str << std::endl;
    if(text.size() < str.size()){
        //Last change is to delete char
        //std::cout << std::to_string(str[getString().size()-1]) << std::endl;
        multiText.addText(std::to_string(str[getString().size()-1]));
        cursorXPos+=multiText.lastLetterWidth();
        cursor.setPosition(cursorXPos, info.cursorPos.y);
    }
    else if(text.size() > str.size()){
        //Last change is to add char
        cursorXPos-=multiText.lastLetterWidth();
        multiText.pop();
        cursor.setPosition(cursorXPos, info.cursorPos.y);
    }
}

void TextInput::setText(std::string t) {
    while (!multiText.empty()){
        cursorXPos-=multiText.lastLetterWidth();
        multiText.pop();
    }
    for(int i = 0; i < t.size(); i++){
        char ch = t[i];
        std::string s;
        s.push_back(ch);
        multiText.addText(s);
        cursorXPos+=multiText.lastLetterWidth();
    }
    cursor.setPosition(cursorXPos, info.cursorPos.y);
}

