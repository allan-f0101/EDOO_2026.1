#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>
#include "Stack.hpp"
#include "Node.hpp"
#include "EmptyStack.hpp"

class LinkedStack : public Stack{
private:
    Node* top;

public:
    LinkedStack() : Stack(), top(nullptr) {}
    ~LinkedStack(){
        clear();
    }

    void push(int item) override {
        Node* novono = new Node(item);
        novono->next = top;
        top = novono;
        _size++;        
    }

    int pop() override {
        if(top == nullptr){
            throw EmptyStack();
        }

        Node* temp = top;
        top = top->next;
        int value = temp->valor;
        delete temp;

        _size--;
        return value;
    }

    int top() override {
        if(top == 0){
            throw EmptyStack();
        }

        return top->valor;
    }

    void clear() override {
        while(_size > 0){
            pop();
        }
    }

};

#endif