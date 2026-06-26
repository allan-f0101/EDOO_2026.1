#include <iostream>

using namespace std;

template<typename E>
class Stack{
private:
    struct Node{
        E data;
        Node* next;

        Node(E d) : data(d), next(nullptr){}
    };

    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0){}
    virtual ~Stack(){
        clear();
    }

    void push(const E& it){
        Node* novono = new Node(it);
        novono->next = top;
        top = novono;
        size++;
    }

    E pop(){
        Node* temp = top;
        top = top->next;
        E value = temp->data;
        delete temp;
        size--;
        return value;
    }

    int length(){
        return size;
    }

    E topValue(){
        return top->data;
    }

    void clear(){
        while(size>0){
            pop();
        }
    }
};

int main(){

    string input;
    
    Stack<int> stack;

    while(cin >> input){
        int direita, esquerda;
        if(input == "+"){
            direita = stack.pop();
            esquerda = stack.pop();
            stack.push(direita+esquerda);
        }

        else if(input == "-"){
            direita = stack.pop();
            esquerda = stack.pop();
            stack.push(esquerda-direita);
        }

        else if(input == "*"){
            direita = stack.pop();
            esquerda = stack.pop();
            stack.push(direita * esquerda);
        }

        else if(input == "END"){
            cout << stack.pop() << "\n";
        }

        else if(input == "EOF"){
            break;
        }

        else{
            int numero = stoi(input);
            stack.push(numero);

        }
    }
    return 0;
}