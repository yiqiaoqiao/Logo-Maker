#ifndef PROJECT1_HISTORY_H
#define PROJECT1_HISTORY_H

#include "HistoryNode.h"
#include "KeyShortcuts.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stack>

class History {
private:
    static std::stack<HistoryNode> stack;
    //static bool undo;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static int size();
    static void undo();
    //static bool isUndo();
};


#endif //PROJECT1_HISTORY_H
