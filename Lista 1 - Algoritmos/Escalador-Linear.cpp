#include <iostream>
#include <string>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int n) : data(n), next(nullptr){}

};

class Queue{
private:
    Node* front;
    Node* rear;

    int size;
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    ~Queue(){
        clear();
    }

    void add(int valor){
        Node* novono = new Node(valor);
        if(front == nullptr){
            front = novono;
            rear = novono;
        }
        else{
            rear->next = novono;
            rear = novono;
        }
        size++;
    }

    //Criar um auxiliar para receber o valor  do front e ir movendo o auxiliar até achar o ID desejado.
    //Não é possível que haja empate de ID.
    //Quando achar o ID desejado faz-se a troca do número da prioridade
    void update(int id, int num_prioridade){
        Node* atual = front;
        
        //Nesse laço me baseei em outra questão que resolvi anteriormente
        //Aqui o ID recebido é multiplipo de 10, mas posso dividir por 10
        //Consequentemente vai dar para usar as posições de 1 em 1.
        id = id / 10;
        int cont = 0;

        while(cont != id && atual != nullptr){
            
            cont++;
        }
        for(int i = 0; i < id - 1; i++){
            atual = atual->next;
        }
    }

    void next(){

    }


    void clear(){};

};

int main(){
    return 0;
}