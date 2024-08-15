#include "History.h"

std::stack<HistoryNode> History::stack;
//bool History::undo = false;

void History::pushHistory(const HistoryNode &snapshot) {
    if(size() == 100){
        //pop the fist one and push the snapshot
        popHistory();
    }
    stack.push(snapshot);
}

HistoryNode& History::topHistory() {
    //std::cout << "Top History" << std::endl;
    if(!stack.empty())
        return stack.top();
    else{
        HistoryNode node{};
        return node;
    }
}

void History::popHistory() {
    if(!stack.empty())
        stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(KeyShortcuts::isUndo()){
        //std::cout << "Undo Key" << std::endl;
        if(size() > 0) {
            stack.top().component->applySnapshot(stack.top().snapshot);
            stack.pop();
        }
    }
}

int History::size(){
    return (int)stack.size();
}

void History::undo() {
    if(size() > 0) {
        stack.top().component->applySnapshot(stack.top().snapshot);
        stack.pop();
    }
}

/*
bool History::isUndo() {
    return undo;
}
*/