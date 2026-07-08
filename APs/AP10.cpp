#include <iostream>
#include <exception>

using namespace std;

class Node{
public:
    int valor;
    Node* next;

    Node(int val) : valor(val), next(nullptr){}
};

class Stack{
private:
    Node* top_node;
    int size;

public:
    Stack() : top_node(nullptr), size(0){}
    ~Stack(){}

    void push(int item){
        Node* novono = new Node(item);
        novono->next = top_node;
        top_node = novono;
        size++;
    }

    int pop(int qtd){
        int soma = 0;
        
        for(int i = 0; i < qtd; i++){
            if(size == 0){
                throw std::runtime_error("Erro de tamanho");
            }

            Node* temp = top_node;
            top_node = top_node->next;
            soma += temp->valor;
            delete temp;
    
            size--;
        }
        return soma;
    }

    int sum(){
        int soma = 0;
        Node* atual = top_node;

        while(atual != nullptr){
            soma += atual->valor;
            atual = atual->next;
        }
        return soma;
    }

    void clear(){
        while(size > 0){
            pop(1);
        }
    }
};

int main(){
    int num;
    cin >> num;
    string input;

    Stack stack;

    for(int i = 0; i < num; i++){
        while(input != "end"){
            cin >> input;

            if(input == "push"){
                int valor;
                cin >> valor;
                stack.push(valor);
            }
            else if(input == "pop"){
                int valor;
                cin >> valor;
                cout << stack.pop(valor) << "\n";
            }
        }
    }

    return 0;
}