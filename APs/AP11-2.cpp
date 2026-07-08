#include <iostream>
#include <string>

using namespace std;

class Node{
public:
    enum Estado{VAZIO, OCUPADO, DELETADO};

    string valor;
    string chave;

    Estado estado;

    Node() : estado(VAZIO), valor(""), chave("") {}
};  

class Dicionario{
private:
    int cont;

    static const int tam = 50;

    Node tabela[tam];

    int Hash(string chave){
        int soma = 0;

        for(char letra : chave){
            soma += letra;
        }

        return soma % tam;
    }

public:
    Dicionario() : cont(0) {
        for(int i = 0; i < tam; i++){
            tabela[i].estado = Node::VAZIO;
        }
    }
    ~Dicionario() {}

    void insert(){}
};

int main(){
    
    Dicionario dict;
    return 0;
}