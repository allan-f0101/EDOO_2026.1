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
        int initialPos = Hash(key);
        
        for(int i = 0; i < 20; i++){
            pos = (Hash(key) + i*i + 23*i) % 101;

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
        int initialPos = (Hash(key) + i*i + 23*i) % 101;

        for(int j = 0; j < 20; j++){

            if(estado[initialPos] == VAZIO){
                return 0;
            }
            else if(estado[initialPos] == OCUPADO && keys[initialPos] == key){
                values[initialPos] = 0;
                estado[initialPos] = DELETADO;
                return;
            }
            else if(estado[initialPos] == OCUPADO || estado[initialPos] == DELETADO){
                
            }
        }
    }

    E find(string key){

    }

    void clear();
    int size();
    
};

int main(){

    return 0;
}