#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Stack{
private:
    struct Node{
        int data;
        Node* next;

        Node(int d) : data(d), next(nullptr) {}
    };

    int size;
    Node* top;
public:
    Stack() : size(0), top(nullptr) {}
    virtual ~Stack(){}

    void push(int value){
        Node* novono = new Node(value);
        novono->next = top;
        top = novono;

        size++;
    }

    void pop(){
        if(top==nullptr){
            throw runtime_error("Erro, my friend!");
        }
        
        Node* temp = top;
        
        top = top->next;

        delete temp;
        size--;
    }

    const int topvalue() const{
        if(top == nullptr){
            throw runtime_error("Erro!");
        }
        return top->data;
    }

    void clear(){
        while(size > 0){
            pop();
        }
    }
};