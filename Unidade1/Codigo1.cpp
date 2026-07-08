#include <iostream>

using namespace std;

template<typename E>
class Pessoa{
private:
    string nome;
    int idade;
    double altura;

public:
    Pessoa() : nome(nome), idade(idade), altura(altura) {}
    ~Pessoa(){}

    void set_name(string nome){this->nome = nome;}
    string get_name(){return nome;}

    void set_idade(int idade){this->idade = idade;}
    int get_idade(){return idade;}

    double set_idade(double altura){this->altura = altura;}
    void get_altura(){return altura;}

};

int main(){

    return 0;
}