#include <iostream>
#include <stdexcept>

using namespace std;

class Queue{
private:
    struct Node{
        int data;
        Node* next;
        
        Node(int d) : data(d), next(nullptr) {}
    };

    int cont;
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr), cont(0) {}
    virtual ~Queue(){
        clear();
    }

    void enqueue(int value){
        Node* novono = new Node(value);
        if(front == nullptr){
            front = novono;
            rear = novono;
        }
        else{
            rear->next = novono;
            rear = novono;
        }
        cont++;
    }
    
    void dequeue(){
        if(front == nullptr){
            throw runtime_error("Erro: Tentativa de remover de uma fila vazia!");
        }

        Node* temp = front;
        front = front->next;

        delete temp;
        cont--;

        if(front == nullptr){
            rear = nullptr;
        }
    }

    const int& frontvalue() const{
        if(front == nullptr){
            throw runtime_error("Erro: tentativa de ler o valor de uma fila vazia!");
        }
        return front->data;
    }

    void clear(){
        while(cont > 0){
            dequeue();
        }
    }
};

// Código da exceção dentro do main(caso faça)

// try{
//     queue.dequeue();
// }
// catch(const runtime_error& e){
//     cout << e.what() << "\n";
// }