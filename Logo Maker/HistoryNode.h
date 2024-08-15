#ifndef PROJECT1_HISTORYNODE_H
#define PROJECT1_HISTORYNODE_H

#include "Snapshot.h"
#include "GUIComponents.h"
#include <iostream>

struct HistoryNode
{
    Snapshot snapshot;
    GUIComponents* component;
};

#endif //PROJECT1_HISTORYNODE_H
