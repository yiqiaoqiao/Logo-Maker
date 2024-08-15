#ifndef TEMPLATEDLINKEDLIST_NODE_ITERATOR_H
#define TEMPLATEDLINKEDLIST_NODE_ITERATOR_H

#include <iostream>
#include <iterator>
#include "node.h"

template <typename T>
class Node_iterator: public std::iterator<std::bidirectional_iterator_tag, T>{
public:
    friend class List;

    Node_iterator();
    Node_iterator(node<T>* p);

    template <typename U>
    friend bool operator ==(const Node_iterator<U>& left, const Node_iterator<U>& right);    //true if left == right

    template <typename U>
    friend bool operator !=(const Node_iterator<U>& left, const Node_iterator<U>& right);    //true if left != right

    T& operator *();         //dereference operator
    const T& operator *() const;         //dereference operator
    T& operator[] (int index);
    Node_iterator<T> operator++(int);   //it++
    Node_iterator<T>& operator++();         //++it
    Node_iterator<T> operator--(int);   //it--
    Node_iterator<T>& operator--();         //--it
    Node_iterator<T>& operator+= (int i);
    Node_iterator<T>& operator-= (int i);
    Node_iterator<T>& operator+ (int i);
    Node_iterator<T>& operator- (int i);

private:
    node<T>* current;
};

#include "Node_iterator.cpp"

#endif //TEMPLATEDLINKEDLIST_NODE_ITERATOR_H
