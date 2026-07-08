#include <iostream>
#include <list>

using namespace std;

class Node{
public:
    int valor;
};

class Dicionario{
private:
    
    int cont;
    static const int tam = 10;
    list<Node> tabela[tam];

    int Hash(int chave){
        return chave%10;
    }


public:
    Dicionario() : cont(0) {
        for(int i = 0; i < tam; i++){
            tabela[i].clear();
        }
    }

    ~Dicionario() {}

    void insert(int item){
        int pos = Hash(item);
        Node novoPar;

        novoPar.valor = item;
        tabela[pos].push_back(novoPar);
    }

    void print(){
        for(int i = 0; i < tam; i++){
            cout << i;

            for(Node elemento : tabela[i]){
                cout << " " << elemento.valor;
            }
            cout << "\n";

        }
    }
};

int main(){
    
    int num;

    cin >> num;

    int input;

    Dicionario dict;

    for(int i = 0; i < num; i++){
        cin >> input;
        dict.insert(input);
    }

    dict.print();
    
    return 0;
}