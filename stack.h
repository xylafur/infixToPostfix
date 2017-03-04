#ifndef LINKEDLIST_STACK
    #define LINKEDLIST_STACK

#include "Util/DoubleLinkedList.h"

template <class T>
class Stack{
private:
    DoubleLinkedList<T> * list;

public:
    Stack(){
        this->list = new DoubleLinkedList<T>();
    }
    ~Stack(){
        delete(list);
    }
    void push(T val){
        list->addToBeg(val);
    }
    T pop(){
        DoubleLinkedListNode<T> * temp = list->popHead();
        T tempVal = temp->getValue();
        delete(temp);
        return tempVal;
    }
    void print(){
        std::cout<<"Head"<<std::endl;
        DoubleLinkedListNode<T> * temp = this->list->getHead();
        while(temp!=NULL){
            std::cout << temp->getValue() << std::endl;
            temp=temp->getNext();
        }
    }
    bool isEmpty(){
        return this->list->getHead() == NULL;
    }

};

#endif
