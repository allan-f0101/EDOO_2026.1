#include <iostream>

using namespace std;

class Node{
public:
    Node* next;
    int chave;

    Node(int c) : next(nullptr), chave(c) {}
};

class StackPrime{
protected:
    int _size;

public:

    StackPrime() : _size(0) {}
    virtual ~StackPrime() {}

    virtual void push(int item) = 0;
    virtual int pop() = 0;
    virtual int topValue() = 0;
    virtual void clear() = 0;
};

class Stack : public StackPrime{
private:
    Node* top;
public: 

    void push(int valor) override{
        Node* novono = new Node(valor);
        novono->next = top;
        top = novono;
        _size++;
    }

    int pop() override{
        if(_size == 0){
            throw runtime_error("Erro!");
        }

        Node* temp = top;
        top = top->next;
        int valor = temp->chave;

        delete temp;
        _size--;
        return valor;
    }

    int topValue(){
        if(_size == 0){
            throw runtime_error("Erro!");
        }
        return top->chave;
    }

    void clear(){
        while(_size > 0){
            pop();
        }
    }
};

int main(){

    return 0;
}