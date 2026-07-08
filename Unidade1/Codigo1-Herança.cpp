#include <iostream>

using namespace std;

class Pessoa{
protected:
    string nome;
    int idade;
    double altura;

public:
    Pessoa() : nome(""), idade(0), altura(0.0) {}
    virtual ~Pessoa(){}

    virtual void set_name(string nome){this->nome = nome;}
    virtual string get_name(){return nome;}

    virtual void set_idade(int idade){this->idade = idade;}
    virtual int get_idade(){return idade;}

    virtual void set_altura(double altura){this->altura = altura;}
    virtual double get_altura(){return altura;}
};

class Joao : public Pessoa{
 
};

int main(){

    Joao j;

    j.set_name("João");
    j.set_idade(23);
    j.set_altura(1.8);

    cout << "Nome" << j.get_name() << endl;
    cout << "Idade" << j.get_idade() << endl;
    cout << "Altura" << j.get_altura() << endl;

    return 0;
}