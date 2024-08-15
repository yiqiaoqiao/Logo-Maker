#ifndef TEMPLATEDLINKEDLIST_NODE_ITERATOR_CPP
#define TEMPLATEDLINKEDLIST_NODE_ITERATOR_CPP
#include "Node_iterator.h"
template <typename T>
Node_iterator<T>::Node_iterator(){
    current = nullptr;
}

template <typename T>
Node_iterator<T>::Node_iterator(node<T>* p)
{
    current = p;
}

template <typename U>
bool operator ==(const Node_iterator<U>& left, const Node_iterator<U>& right)    //true if left == right
{
    return (left.current == right.current);
}

template <typename U>
bool operator !=(const Node_iterator<U>& left, const Node_iterator<U>& right)    //true if left != right
{
    return (!(left == right));
}

template <typename T>
T& Node_iterator<T>::operator *()         //dereference operator
{
    assert(current != nullptr);

    //returns the item in the list
    return current->data;
}

template <typename T>
const T& Node_iterator<T>::operator *() const         //dereference operator
{
    assert(current != nullptr);

    //returns the item itself
    return *current;
}

template <typename T>
T& Node_iterator<T>::operator[] (int index)
{
    assert(index >= 0);

    //Same as at function in node
    return (current+index)->data;
}

template <typename T>
Node_iterator<T> Node_iterator<T>::operator++(int)
{
    assert(current != nullptr);
    Node_iterator<T> temp = current;
    current++;
    return temp;
}

template <typename T>
Node_iterator<T>& Node_iterator<T>::operator++()
{
    assert(current != nullptr);
    current = current ->next;
    return *this;
}

template <typename T>
Node_iterator<T> Node_iterator<T>::operator--(int)
{
    assert(current != nullptr);
    Node_iterator<T> temp = current;
    current--;
    return temp;
}

template <typename T>
Node_iterator<T>& Node_iterator<T>::operator--()
{
    assert(current != nullptr);
    current = current ->prev;
    return *this;
}

template <typename T>
Node_iterator<T>& Node_iterator<T>::operator+= (int i){
    current->next = new Node_iterator<T>(i);
    return current->next;
}

template <typename T>
Node_iterator<T>& Node_iterator<T>::operator-= (int i){
    current->prev = new Node_iterator<T>(i);
    return current->prev;
}

template <typename T>
Node_iterator<T>& Node_iterator<T>::operator+ (int i){
    current->next = new Node_iterator<T>(i);
    return current;
}

template <typename T>
Node_iterator<T>& Node_iterator<T>::operator- (int i){
    current->prev = new Node_iterator<T>(i);
    return current;
}


#endif //TEMPLATEDLINKEDLIST_NODE_ITERATOR_CPP
