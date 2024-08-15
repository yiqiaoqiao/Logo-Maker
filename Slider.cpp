#include "Slider.h"

Slider::Slider() {
    text.setString("");
    text.setColor(sf::Color::White);
    number.setString("");
    number.setColor(sf::Color::White);
    bar.setColor(sf::Color::White);
    dot.setFillColor(sf::Color::White);
    bar.setSize(500,3);
    bar.setPosition(0,0);
    dot.setRadius(13);
    dot.setPosition(0,0);
    n = 0;
    prevN = 0;
    i = -1;
    addSnapshot = false;
}

void Slider::setBarSize(float x, float y) {
    bar.setSize(x,y);
}

void Slider::setBarPosition(float x, float y) {
    bar.setPosition(x,y);
}

void Slider::setDotRadius(float r) {
    dot.setRadius(r);
}

void Slider::setDotPosition(float x, float y) {
    dot.setPosition(x,y);
}

void Slider::setText(std::string s) {
    text.setString(s);
}

sf::Rect<float> Slider::getGlobalBounds() {
    sf::Rect<float> bounds = text.getGlobalBound();
    float widthLimit = number.getGlobalBound().left+number.getGlobalBound().width;
    bounds.width = widthLimit - bounds.left;
    //std::cout << text.getString() << std::endl;
    //std::cout << "Left: " << bounds.left << " Width: " << bounds.width << std::endl;
    //std::cout << "Top: " << bounds.top << " Height: " << bounds.height << std::endl;
    return bounds;
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
    window.draw(bar);
    window.draw(dot);
    window.draw(number);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //snapshot = getSnapshot();
    if(MouseEvents::draggedOver(*this, window, event)){
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        if (mousePos.x >= bar.getGlobalBound().left
        && mousePos.x <= bar.getGlobalBound().left + bar.getGlobalBound().width) {
            setDotCenter(mousePos.x, dot.getGlobalBounds().top + dot.getRadius());
        }
    }
    else if(sf::Event::MouseButtonReleased){
        if(prevN != n) {
            addSnapshot = true;
            /*
            prevN = n;
            snapshot.setValue(n);
            std::cout << "Push to History stack" << std::endl;
            History::pushHistory({snapshot, this});
             */
        }
    }
}

void Slider::update() {
    //DO NOTHING
    n = std::round(dot.getGlobalBounds().left+dot.getRadius()-bar.getGlobalBound().left);
    n /= 3;
    //std::cout << "num: " << num << std::endl;
    number.setString(std::to_string(n));
}

Snapshot &Slider::getSnapshot() {
    return snapshot;
}

void Slider::applySnapshot(const Snapshot &snapshot) {
    this->snapshot = snapshot;
    setDot(snapshot.getValue());
}

void Slider::setPosition(float x, float y) {
    //Draw circle on the left of the bar, and text in front and number behind
    text.setPosition(x,y);
    bar.setPosition(text.getGlobalBound().left + text.getGlobalBound().width+40,
                    text.getGlobalBound().top+ text.getGlobalBound().height/2);
    setDotCenter(bar.getGlobalBound().left, bar.getGlobalBound().top);
    //dot.setPosition(bar.getGlobalBound().left, bar.getGlobalBound().top);
    //std::cout << "Bar left position: " << bar.getGlobalBound().left << ", " << bar.getGlobalBound().top << std::endl;
    //dot.setOrigin(bar.getGlobalBound().left, bar.getGlobalBound().top);
    number.setPosition(bar.getGlobalBound().left+bar.getGlobalBound().width+20,
                       y);
}

void Slider::setTextSize(int s) {
    text.setCharacterSize(s);
    number.setCharacterSize(s);
}

void Slider::setNumber(std::string s) {
    number.setString(s);
}

void Slider::setDotCenter(float x, float y) {
    //std::cout << "Bar position: " << x << ", " << y << std::endl;
    dot.setPosition(x-dot.getRadius(), y-dot.getRadius());
    //std::cout << "dot new center position: " << dot.getGlobalBounds().left+dot.getRadius()
    //<< ", " << dot.getGlobalBounds().top+dot.getRadius() << std::endl;
}

sf::Rect<float> Slider::getBarGlobalBounds() {
    return bar.getGlobalBound();
}

sf::Rect<float> Slider::getTextGlobalBounds() {
    return text.getGlobalBound();
}

sf::Rect<float> Slider::dragGlobalBounds() {
    return dot.getGlobalBounds();
}

int Slider::getN() {
    return n;
}

void Slider::reset() {
    setPosition(text.getPosition().x, text.getPosition().y);
    n = 0;
    prevN = 0;
}

void Slider::setDot(int p) {
    //std::cout << "p: " << p << std::endl;
    n = p;
    prevN = p;
    //std::cout << "Set n: " << n << std::endl;
    float xPos = (float)n*3+bar.getGlobalBound().left;
    setDotCenter(xPos,dot.getGlobalBounds().top+dot.getRadius());
}

void Slider::setI(int i) {
    this->i = i;
}

bool Slider::shouldApply() {
    return addSnapshot;
}

void Slider::resetSnapshotState() {
    addSnapshot = false;
    prevN = n;
}

void Slider::setN(int n) {
    this->n = n;
    setDot(n);
}

