#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack{
protected:
    int _size;

public:
    Stack() : _size(0){}
    virtual ~Stack() {}
    virtual void push(int item) = 0;
    virtual int pop() = 0;
    virtual int top() = 0;
    virtual void clear() = 0;
    int size(){return this->_size;}

};

#endif