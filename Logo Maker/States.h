#ifndef PROJECT1_STATES_H
#define PROJECT1_STATES_H

#include <map>
#include <iostream>
#include "ObjectStates.h"

class States {
private:
    std::map<ObjectStates, bool> states;
public:
    States();
    bool checkState(ObjectStates state) const;
    void disableState(ObjectStates state);
    void enableState(ObjectStates state);
};


#endif //PROJECT1_STATES_H
