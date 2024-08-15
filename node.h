#ifndef TEMPLATEDLINKEDLIST_NODE_H
#define TEMPLATEDLINKEDLIST_NODE_H

template <typename T>
struct node{
    T data;
    node<T>* next;
    node<T>* prev;
    node(const T& item = T(), node<T>* nextptr = nullptr, node<T>* prevptr = nullptr):
            data(item), next(nextptr), prev(prevptr) {/*Do nothing*/}
    /*
    friend ostream& operator << (ostream& outs, const node<T> n)
    {
        outs << n._item;
        return outs;
    }
    */
};

#endif //TEMPLATEDLINKEDLIST_NODE_H
