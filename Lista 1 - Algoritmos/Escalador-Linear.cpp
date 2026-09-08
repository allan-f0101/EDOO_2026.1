#include <iostream>
#include <string>

using namespace std;

class Elemento{
public:
    int id;
    int prioridade;
};

class Node{
public:
    Elemento data;
    Node* next;

    Node(int id, int prio) : data{id, prio}, next(nullptr){}

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

    void add(int id, int prioridade){
        Node* novono = new Node(id, prioridade);
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
        
        while(atual != nullptr){

            if(atual->data.id == id){
                atual->data.prioridade = num_prioridade;
                return;
            }

            atual = atual->next;
        }
        
    }

    //Roda a fila inteira fazendo a comparação entre os valores para achar 
    //as restrições exigidas
    void next(){

        if(front == nullptr){
            cout << "Fila Vazia"<< endl;
            return;
        }

        Node* atual = front;
        int maior = atual->data.prioridade;
        int menor_id = atual->data.id;

        while(atual != nullptr){
            if(maior < atual->data.prioridade){
                maior = atual->data.prioridade;
                menor_id = atual->data.id;
            }
            
            else if(maior == atual->data.prioridade){
                if(menor_id > atual->data.id){
                    menor_id = atual->data.id;
                }
            }
            atual=atual->next;
        }

        //Caso o elemento a ser removido for o front:

        if(front->data.id == menor_id){
            int num_operacoes = 1;
            Node* temp = front;

            front=front->next;

            if(front==nullptr){
                rear = nullptr;
            }

            delete temp;
            size--;

            cout << menor_id << ' ' << num_operacoes << " " << size << endl;
            return;
        }
        
        // Caso seja algum outro elemento da fila
        atual = front;
        int num_operacoes = 1;

        while(atual->next != nullptr){
            num_operacoes++;
            if(atual->next->data.id == menor_id){
                Node* temp = atual->next;
                atual->next = temp->next;

                if(temp == rear){
                    rear = atual;
                }

                delete temp;
                size--;
                cout << menor_id << " " << num_operacoes << " " << size << endl;
                return;
            }
            atual = atual->next;
        }
    }

    void clear(){
        while(size > 0){
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
        rear = nullptr;
        size = 0;
    }

};

void add_element(Queue& queue){
    int id, num_prioridade;
    cin >> id >> num_prioridade;
    queue.add(id, num_prioridade);
}

void update_element(Queue& queue){
    int id, num_prioridade;
    cin >> id >> num_prioridade;
    queue.update(id, num_prioridade);
}

int main(){

    Queue queue;

    int num;
    cin >> num;

    string input;

    for(int i = 0; i < num; i++){
        cin >> input;

        if(input == "ADD"){
            add_element(queue);
        }
        else if(input == "UPDATE"){
            update_element(queue);
        }
        else if(input == "NEXT"){
            queue.next();  
        } 
    }
    return 0;
}