#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Node.hpp"
#include "Stack.hpp"
#include <iostream>
#include <exception>

template<typename T>
class LinkedStack : public Stack<T>{
private:
    Node<T>* top_node;

public:
    LinkedStack() : top_node(nullptr) {}
    ~LinkedStack();

    void push(T v) override;
    T pop() override;
    T top() override;
    void clear() override;
    int length() override;
};


template<typename T>
LinkedStack<T>::~LinkedStack(){
    this->clear();
}

template<typename T>
void LinkedStack<T>::push(T v){
    Node<T>* novono = new Node<T>(v);
    novono->next = top_node;
    top_node = novono;
    this->_size++;  
}

template<typename T>
T LinkedStack<T>::pop(){
    if(this->_size == 0){
        throw std::runtime_error("Errou, mai biurifou");
    }

    Node<T>* temp = top_node;
    top_node = top_node->next;
    T valor = temp->data;
    delete temp;
    this->_size--;
    return valor;
}

template<typename T>
T LinkedStack<T>::top()
{
    if(this->_size == 0){
        throw std::runtime_error("Errou, mai biurifou");
    }
    return top_node->data;
}

template<typename T>
void LinkedStack<T>::clear(){
    while(this->_size > 0){
        pop();
    }
}

template<typename T>
int LinkedStack<T>::length(){
    return this->_size;
}

#endif