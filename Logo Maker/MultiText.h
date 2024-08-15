#ifndef MULTITEXT_MULTITEXT_H
#define MULTITEXT_MULTITEXT_H

#include <iostream>
#include "LinkedList.h"
#include "Letter.h"
#include "Font.h"

class MultiText: public sf::Drawable {
private:
    LinkedList<Letter> list;
    float x;
    float y;
    int characterSize;
    //sf::Font font;
    //float lastWidth;
public:
    MultiText();
    MultiText(const MultiText& RHS);
    MultiText& operator =(const MultiText& RHS);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addText(std::string s);
    void setPosition(float x, float y);
    //void setSetting();
    bool empty() const;
    void pop();
    void changeToWhite();
    void changeToBlack();
    void adjustColor();
    void changeColor(sf::Color color, int i);
    float lastLetterWidth();
    float lastLetterXPos() const;
    int size();
    LinkedList<Letter> getList();
    void copyMultiText(const MultiText &RHS);
    void setLetterSize(int size);
    Node_iterator<struct Letter> begin() const;
    Node_iterator<struct Letter> end() const;
    std::string getString();
    void clear();
};


#endif //MULTITEXT_MULTITEXT_H
