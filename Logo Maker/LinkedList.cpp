#ifndef TEMPLATEDLINKEDLIST_LINKEDLIST_CPP
#define TEMPLATEDLINKEDLIST_LINKEDLIST_CPP
#include "LinkedList.h"

//--------------------------- FXN DEFINITION ---------------------------------
template <class T>
LinkedList<T>::LinkedList(): head(nullptr){
    //DO NOTHING
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyThis){
    copyList(copyThis);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T>& RHS){
    //std::cout << "Linked List Operator = " << std::endl;
    if(this == &RHS){
        return *this;
    }
    clear();
    //std::cout << "Here" << std::endl;
    copyList(RHS);
    //std::cout << "Here" << std::endl;
    return *this;
}

template <class T>
LinkedList<T>::~LinkedList(){
    clear();
}

template <class T>
void LinkedList<T>::insertHead(const T& i){
    node<T>* temp = new node<T>(i);
    temp->prev = nullptr;
    temp->next = head;
    head = temp;
}

template <class T>
void LinkedList<T>::insertTail(const T& i){
    if(head == nullptr)
        insertHead(i);
    else{
        node<T>* walker = head;
        while(walker->next != nullptr){
            walker = walker->next;
        }
        node<T>* temp = new node<T>(i);
        temp->next = nullptr;
        temp->prev = walker;
        walker->next = temp;
    }
}

template <class T>
void LinkedList<T>::insertBefore(const T& i, const T& beforeThis){
    node<T>* temp = find(beforeThis);
    if(temp != nullptr){
        //std::cout << "data: " << temp->data << std::endl;
        //Check for head ptr:
        if(temp->prev == nullptr){
            insertHead(i);
        }
        else{
            node<T>* prevNode = temp->prev;
            node<T>* newNode = new node<T>(i);
            //prevNode -> newNode -> temp
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = temp;
            temp->prev = newNode;
        }
    }
}

template <class T>
void LinkedList<T>::insertAfter(const T& i, const T& afterThis){
    node<T>* temp = find(afterThis);
    if(temp != nullptr){
        //Check for next node
        if(temp->next == nullptr){
            insertTail(i);
        }
        else{
            node<T>* nextNode = temp->next;
            node<T>* newNode = new node<T>(i);
            //temp -> newNode -> nextNode;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nextNode;
            nextNode->prev = newNode;
        }
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator +=(const T& i){
    insertTail(i);
    return *this;
}

template <class T>
node<T>* LinkedList<T>::find(const T& i){
    //std::cout << "i: " << i << std::endl;
    node<T>* walker = head;
    while (walker != nullptr){
        if(walker->data == i) {
            //std::cout << "Contain " << i << std::endl;
            return walker;
        }
        walker = walker->next;
    }
    return nullptr;
}

template <class T>
void LinkedList<T>::remove(const T& i){
    node<T>* temp = find(i);
    node<T>* prevNode = temp->prev;
    node<T>* nextNode = temp->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete temp;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
    if(head == nullptr)
        return true;
    return false;
}

template <class T>
int LinkedList<T>::getSize() const {
    node<T>* walker = head;
    int count = 0;
    while(walker != nullptr)
    {
        count++;
        walker = walker->next;
    }
    return count;
}

template <class T>
void LinkedList<T>::clear(){
    if(head != nullptr){
        node<T>* walker = head->next;
        while(walker != nullptr){
            delete head;
            head = walker;
            walker = walker->next;
        }
        //delete head;
        head = nullptr;
    }
}

template <class T>
void LinkedList<T>::copyList(const LinkedList<T>& list){
    //std::cout << "copy list" << std::endl;
    clear();
    if(list.head == nullptr)
        head = nullptr;
    else{
        //std::cout << "Here" << std::endl;
        node<T>* walker = list.head;
        while (walker != nullptr){
            insertTail(walker->data);
            walker = walker->next;
        }
    }
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() const {
    return Node_iterator<T>(head);
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end() const {
    return Node_iterator<T>(nullptr);
}

template <class T>
void LinkedList<T>::removePos(const int& pos){
    assert(pos < getSize());
    node<T>* walker = head;
    for(int i = 0; i < pos; i++){
        walker = walker->next;
    }
    if(walker == head){
        head = head->next;
    }
    else if(walker->next == nullptr){
        node<T>* p = walker->prev;
        p->next = nullptr;
    }
    else{
        node<T>* p = walker->prev;
        node<T>* n = walker->next;
        p->next = n;
        n->prev = p;
    }
    delete walker;
}

template <class T>
T LinkedList<T>::findPos(const int& pos) const {
    assert(pos < getSize());
    node<T>* walker = head;
    for(int i = 0; i < pos; i++)
        walker = walker->next;
    return walker->data;
}

template <class U>
std::ostream& operator << (std::ostream& outs, const LinkedList<U>& object){
    node<U>* walker = object.head;
    while (walker != nullptr){
        outs << walker->data << " ";
        walker = walker->next;
    }
    outs << std::endl;
    return outs;
}

#endif //TEMPLATEDLINKEDLIST_LINKEDLIST_CPP