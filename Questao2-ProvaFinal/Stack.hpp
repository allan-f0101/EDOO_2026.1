#ifndef STACK_H
#define STACK_H

#include "Node.hpp"

class EmptyStack{
private:
    std::string message;

public:
    EmptyStack(const std::string& s) : message(s){}
    const std::string& get_message(){return this->message;}
};

template<typename T>
class Stack{
protected:
    int _size;

public:
    Stack() : _size(0){}
    virtual ~Stack(){}

    virtual void push(T item) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual void clear() = 0;
    virtual int length() = 0;

};

#endif