#ifndef TEMPLATEDLINKEDLIST_LINKEDLIST_H
#define TEMPLATEDLINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <cassert>
#include "node.h"
#include "Node_iterator.h"

template <class T>
class LinkedList {
public:
    typedef Node_iterator<T> iterator;
    LinkedList();

    //Big Three
    LinkedList(const LinkedList<T>& copyThis);
    LinkedList& operator =(const LinkedList<T>& RHS);
    ~LinkedList();
    void insertHead(const T& i);
    void insertTail(const T& i);
    void insertBefore(const T& i, const T& beforeThis);
    void insertAfter(const T& i, const T& afterThis);
    LinkedList<T>& operator +=(const T& i);
    node<T>* find(const T& i);
    void remove(const T& i);
    void removePos(const int& pos);
    T findPos(const int& pos) const;
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void copyList(const LinkedList<T>& list);
    iterator begin() const;
    iterator end() const;
    template <class U>
    friend std::ostream& operator << (std::ostream& outs, const LinkedList<U>& object);

private:
    node<T>* head;
};

#include "LinkedList.cpp"

#endif //TEMPLATEDLINKEDLIST_LINKEDLIST_H
