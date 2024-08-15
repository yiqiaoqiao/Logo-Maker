#include "Snapshot.h"

Snapshot& Snapshot::operator =(const Snapshot& RHS){
    if(this == &RHS){
        return *this;
    }
    text = RHS.text;
    textColor = RHS.textColor;
    textListColor = RHS.textListColor;
    backgroundColor = RHS.backgroundColor;
    backgroundListColor = RHS.backgroundListColor;
    fontName = RHS.fontName;
    textPosition = RHS.textPosition;
    shadowPosition = RHS.shadowPosition;
    fontSize = RHS.fontSize;
    textOpacity = RHS.textOpacity;
    shadowOpacity = RHS.shadowOpacity;
    backgroundOpacity = RHS.backgroundOpacity;
    skew = RHS.skew;
    return *this;
}

void Snapshot::setText(std::string t) {
    text = t;
}

void Snapshot::setTextColor(sf::Color c) {
    textColor = c;
}

void Snapshot::setBackgroundColor(sf::Color c) {
    backgroundColor = c;
}

void Snapshot::setFontName(std::string name) {
    fontName = name;
}

void Snapshot::setTextPosition(sf::Vector2f pos) {
    textPosition = pos;
}

void Snapshot::setShadowPosition(sf::Vector2f pos) {
    shadowPosition = pos;
}

void Snapshot::setFontSize(int size) {
    fontSize = size;
}

void Snapshot::setTextOpacity(int o) {
    textOpacity = o;
}

void Snapshot::setShadowOpacity(int o) {
    shadowOpacity = o;
}

void Snapshot::setBackgroundOpacity(int o) {
    backgroundOpacity = o;
}

void Snapshot::setSkew(float s) {
    skew = s;
}

std::string Snapshot::getText() const{
    return text;
}

sf::Color Snapshot::getTextColor() const {
    return textColor;
}

sf::Color Snapshot::getBackgroundColor() const {
    return backgroundColor;
}

std::string Snapshot::getFontName() const {
    return fontName;
}

sf::Vector2f Snapshot::getTextPosition() const {
    return textPosition;
}

sf::Vector2f Snapshot::getShadowPosition() const {
    return shadowPosition;
}

int Snapshot::getFontSize() const {
    return fontSize;
}

int Snapshot::getTextOpacity() const {
    return textOpacity;
}

int Snapshot::getShadowOpacity() const {
    return shadowOpacity;
}

int Snapshot::getBackgroundOpacity() const {
    return backgroundOpacity;
}

float Snapshot::getSkew() const {
    return skew;
}

void Snapshot::setTextListColor(sf::Color c) {
    textListColor = c;
}

void Snapshot::setBackgroundListColor(sf::Color c) {
    backgroundListColor = c;
}

sf::Color Snapshot::getBackgroundListColor() const{
    return backgroundListColor;
}

sf::Color Snapshot::getTextListColor() const{
    return textListColor;
}

void Snapshot::setValue(int v) {
    value = v;
}

int Snapshot::getValue() const{
    return value;
}

/*
void Snapshot::setMultiText(MultiText m) {
    multiText = m;
}

void Snapshot::setCursorXPos(float x) {
    cursorXPos = x;
}

MultiText Snapshot::getMultiText() const{
    return multiText;
}

float Snapshot::getCursorXPos() const{
    return cursorXPos;
}
*/