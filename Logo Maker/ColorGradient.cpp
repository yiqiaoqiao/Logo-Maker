#include "ColorGradient.h"

ColorGradient::ColorGradient() {
    choseColor = sf::Color::Red;
    size = 256*2;
    gradient = sf::VertexArray(sf::Points, size*size);
    int hue = 240;
    int h = 240/60;
    float f = float(hue) / 60-h;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++) {
            gradient[i * size + j].position = sf::Vector2f(i,j);
        }
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            float v = float (j / (size*1.0));
            float s = float (i / (size*1.0));
            float p = v*(1.f - s);
            float q = v*(1.f-s*f);
            float t = v*(1.f-s*(1-f));
            sf::Color c;
            c = sf::Color(t*255, p*255, v*255);
            gradient[i * size + j].color = c;
        }
    }
}

void ColorGradient::setPosition(float x, float y) {
    for(int i = 0; i < size*size; i++){
        gradient[i].position.x += x;
        gradient[i].position.y += y;
    }
}

void ColorGradient::setColor(int hue) {
    if(hue == -1){
        //White Color
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++) {
                gradient[i * size + j].color = sf::Color::White;
            }
        }
    }
    else if(hue == -2){
        //Black Color
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++) {
                gradient[i * size + j].color = sf::Color::Black;
            }
        }
    }
    else{
        //std::cout << "hue: " <<
        int h = hue/60;
        float f = float(hue) / 60-h;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                float v = float (j / (size*1.0));
                float s = float (i / (size*1.0));
                float p = v*(1.f - s);
                float q = v*(1.f-s*f);
                float t = v*(1.f-s*(1-f));
                sf::Color c;
                switch (h) {
                    case 0:
                        c = sf::Color(v*255, t*255, p*255);
                        break;
                    case 1:
                        c = sf::Color(q*255, v*255, p*255);
                        break;
                    case 2:
                        c = sf::Color(p*255, v*255, t*255);
                        break;
                    case 3:
                        c = sf::Color(p*255, q*255, v*255);
                        break;
                    case 4:
                        c = sf::Color(t*255, p*255, v*255);
                        break;
                    case 5:
                        c = sf::Color(v*255, p*255, q*255);
                        break;
                    case 6:
                        c = sf::Color(v*255, t*255, p*255);
                        break;
                }
                gradient[i * size + j].color = c;
            }
        }
    }
}

void ColorGradient::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!checkState(HIDDEN)) {
        //std::cout << "Draw" << std::endl;
        window.draw(gradient);
    }
}

void ColorGradient::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents::mouseClicked(*this, window)){
        //Click on this gradient
        sf::Vector2f mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);
        int i = int (mousePos.x - gradient[0].position.x);
        int j = int (mousePos.y - gradient[0].position.y);
        choseColor = gradient[i*size+j].color;
        //enableState(HIDDEN);
    }
    else if(MouseEvents::mouseClicked(window, event))
        enableState(HIDDEN);
}

void ColorGradient::update() {
    //DO NOTHING
}

Snapshot &ColorGradient::getSnapshot() {
    //DO NOTHING
}

void ColorGradient::applySnapshot(const Snapshot &snapshot) {
    //DO NOTHING
}

void ColorGradient::setColor(sf::Color c) {
    int h = findHue(c);
    setColor(h);
}

int ColorGradient::findHue(sf::Color c) {
    if(c == sf::Color::Red)
        return 0;
    else if(c == sf::Color::Yellow)
        return 60;
    else if(c == sf::Color::Blue)
        return 240;
    else if(c == sf::Color::Green)
        return 120;
    else if(c == sf::Color::Magenta)
        return 300;
    else if(c == sf::Color::Cyan)
        return 180;
    else if(c == sf::Color::White)
        return -1; //White
    return -2; //Black
}

sf::Rect<float> ColorGradient::getGlobalBounds() {
    sf::Rect<float> bounds;
    bounds.left = gradient[0].position.x;
    bounds.top = gradient[0].position.y;
    bounds.width = (float)size;
    bounds.height = (float)size;
    return bounds;
}

sf::Color ColorGradient::getChoseColor() {
    return choseColor;
}

void ColorGradient::reset() {
    choseColor = sf::Color::Red;
    setColor(sf::Color::Red);
    enableState(HIDDEN);
}

void ColorGradient::setChoseColor(sf::Color c) {
    choseColor = c;
}
