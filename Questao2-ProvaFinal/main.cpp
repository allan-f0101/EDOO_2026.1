#include "LinkedStack.hpp"
#include <iostream>

using namespace std;

int main(){
    LinkedStack<int> pilha;
    pilha.push(10);
    pilha.push(20);

    cout << "Topo atual: " << pilha.top() << endl;
    cout << "Tamanho: " << pilha.length() << endl;

    pilha.pop();
    cout << "Novo topo: " << pilha.top() << endl;

    return 0;
}