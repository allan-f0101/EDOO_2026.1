#include <iostream>
#include <string>

using namespace std;

template<typename E>
class Dictionary{
private:
    enum Estado{VAZIO, OCUPADO, DELETADO};

    static const int tam = 101;
    string keys[tam];
    E values[tam];
    Estado estado[tam];
    int cont;

    int Hash(string key){
        int forCont = 1;
        int sum = 0;

        for(char i : key){
            sum += i * forCont;
            forCont++;
        }

        int function = 19 * sum;
        
        return function % 101;
    };

public:
    Dictionary() : cont(0) {
        for(int i = 0; i < tam; i++){
            estado[i] = VAZIO;
        }
    }
    ~Dictionary();

    void insert(string key, E value){        
        for(int i = 0; i < 20; i++){
            int pos = (Hash(key) + i*i + 23*i) % 101;

            if(estado[pos] == VAZIO || estado[pos] == DELETADO){
                keys[pos] = key;
                values[pos] = value;
                estado[pos] = OCUPADO;
                cont++;
                return;
            }

            else if(estado[pos] == OCUPADO && keys[pos] == key){
                return;
            }
        }
    }

    E remove(string key){
        for(int j = 0; j < 20; j++){
            int pos = (Hash(key) + j*j + 23*j) % 101;
            if(estado[pos] == VAZIO){
                break;
            }

            if(estado[pos] == OCUPADO && keys[pos] == key){
                estado[pos] = DELETADO;
                cont--;
                return values[pos];
            }
        }
        return E();
    }

    E find(string key){
        for(int j = 0; j < 20; j++){
            int pos = (Hash(key) + j*j + 23*j) % 101;

            if(estado[pos] == VAZIO){
                return E();
            }

            if(estado[pos] == OCUPADO && keys[pos] == key){
                return values[pos];
            }
        }
        return E();
    }

    void clear(){
        for(int i = 0; i < tam; i++){
            estado[i] = VAZIO;
        }
        cont = 0;
    }
    int size(){
        return cont;
    }
    
};

int main(){

    return 0;
}