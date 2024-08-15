#include "SliderList.h"

SliderList::SliderList() {
    //Text Opacity
    Slider s1;
    s1.setText("Text Opacity:");
    s1.setBarSize(767,2);
    s1.setPosition(30, 1000);
    s1.setI(0);
    list.push_back(s1);

    //Font Size
    Slider s2;
    s2.setText("Font Size:");
    s2.setBarSize(301,2);
    //std::cout << s1.getGlobalBounds().left + s1.getGlobalBounds().width + 100 << std::endl;
    s2.setPosition(s1.getGlobalBounds().left + s1.getGlobalBounds().width + 100, s1.getGlobalBounds().top);
    s2.setI(1);
    list.push_back(s2);

    //Skew
    Slider s3;
    s3.setText("Skew:");
    s3.setBarSize(301, 2);
    //std::cout << s2.getGlobalBounds().left + s2.getGlobalBounds().width + 100 << std::endl;
    s3.setPosition(s2.getGlobalBounds().left + s2.getGlobalBounds().width + 100, s1.getGlobalBounds().top);
    s3.setI(2);
    list.push_back(s3);

    //Shadow Opacity
    Slider s4;
    s4.setText("Shadow Opacity:");
    s4.setBarSize(720,2);
    s4.setPosition(s1.getGlobalBounds().left, s1.getGlobalBounds().top+s1.getGlobalBounds().height+50);
    s4.setI(3);
    list.push_back(s4);

    //Background Opacity
    Slider s5;
    s5.setText("Background Opacity:");
    s5.setBarSize(765,2);
    s5.setPosition(s4.getGlobalBounds().left + s4.getGlobalBounds().width + 100, s4.getGlobalBounds().top);
    s5.setI(4);
    list.push_back(s5);

    //Text X-Axis
    Slider s6;
    s6.setText("Text X-Axis:");
    s6.setBarSize(1920,2);
    s6.setPosition(s4.getGlobalBounds().left, s4.getGlobalBounds().top+s4.getGlobalBounds().height+50);
    s6.setI(5);
    list.push_back(s6);

    //Text Y-Axis
    Slider s7;
    s7.setText("Text Y-Axis:");
    s7.setBarSize(1920,2);
    s7.setPosition(s6.getGlobalBounds().left, s6.getGlobalBounds().top+s6.getGlobalBounds().height+50);
    s7.setI(6);
    list.push_back(s7);

    //Shadow X-Axis
    Slider s8;
    s8.setText("Shadow X-Axis:");
    s8.setBarSize(1920,2);
    s8.setPosition(s7.getGlobalBounds().left, s7.getGlobalBounds().top+s7.getGlobalBounds().height+50);
    s8.setI(7);
    list.push_back(s8);

    //Shadow Y-Axis
    Slider s9;
    s9.setText("Shadow Y-Axis:");
    s9.setBarSize(1920,2);
    s9.setPosition(s8.getGlobalBounds().left, s8.getGlobalBounds().top+s8.getGlobalBounds().height+50);
    s9.setI(8);
    list.push_back(s9);
}

void SliderList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(int i = 0; i < list.size(); i++){
        window.draw(list.at(i));
    }
}

void SliderList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    snapshot = getSnapshot();
    snapshot.setSkew(getSkew());
    snapshot.setShadowOpacity(getShadowOpacity());
    snapshot.setTextOpacity(getTextOpacity());
    snapshot.setBackgroundOpacity(getBackgroundOpacity());
    snapshot.setFontSize(getFontSize());
    snapshot.setTextPosition(getTextPosition());
    snapshot.setShadowPosition(getShadowPosition());
    int pos = -1;
    for(int i = 0; i < list.size(); i++){
        list.at(i).addEventHandler(window, event);
        if(list.at(i).shouldApply()){
            //Should add snapshot to the history stack
            pos = i;
        }
    }
    if(pos != -1) {
        //std::cout << "Push snapshot to History stack" << std::endl;
        History::pushHistory({snapshot, this});
        list.at(pos).resetSnapshotState();
    }
}

void SliderList::update() {
    for(int i = 0; i < list.size(); i++){
        list.at(i).update();
    }
}

Snapshot &SliderList::getSnapshot() {
    return snapshot;
}

void SliderList::applySnapshot(const Snapshot &snapshot) {
    this->snapshot = snapshot;
    setTextPosition(snapshot.getTextPosition());
    setShadowPosition(snapshot.getShadowPosition());
    setFontSize(snapshot.getFontSize());
    setTextOpacity(snapshot.getTextOpacity());
    setBackgroundOpacity(snapshot.getBackgroundOpacity());
    setShadowOpacity(snapshot.getShadowOpacity());
    setSkew(snapshot.getSkew());
}

sf::Vector2f SliderList::getTextPosition() {
    return {(float)list.at(5).getN()*3, (float)list.at(6).getN()*2};
}

int SliderList::getFontSize() {
    return list.at(1).getN()*3;
}

int SliderList::getTextOpacity() {
    return list.at(0).getN();
}

int SliderList::getShadowOpacity() {
    return list.at(3).getN();
}

int SliderList::getBackgroundOpacity() {
    return list.at(4).getN();
}


float SliderList::getSkew() {
    return (float)list.at(2).getN()/100;
}

sf::Vector2f SliderList::getShadowPosition() {
    return {(float)list.at(7).getN()*3, (float)list.at(8).getN()*2};
}

void SliderList::reset() {
    for(int i = 0; i < list.size(); i++){
        list.at(i).reset();
    }
}

void SliderList::setTextPosition(sf::Vector2f pos) {
    float x = pos.x/3;
    int y = (int)pos.y/2;
    list.at(5).setDot((int)x);
    list.at(6).setDot(y);
}

void SliderList::setShadowPosition(sf::Vector2f pos) {
    float x = pos.x/3;
    int y = (int)pos.y/2;
    list.at(7).setDot((int)x);
    list.at(8).setDot(y);
}

void SliderList::setFontSize(int s) {
    list.at(1).setDot(s/3);
}

void SliderList::setTextOpacity(int s) {
    list.at(0).setDot(s);
}

void SliderList::setShadowOpacity(int s) {
    list.at(3).setDot(s);
}

void SliderList::setBackgroundOpacity(int s) {
    list.at(4).setDot(s);
}

void SliderList::setSkew(float s) {
    list.at(2).setDot(int(s*100));
}
