#include <iostream>
#include <string>

using namespace std;

template<typename E>
class Dictionary{
private:
    enum Estado{VAZIO, OCUPADO, DELETADO};

    static const int tam = 101;
    E values[tam];
    Estado estado[tam];
    int cont;

public:
    Dictionary() : cont(0) {
        for(int i = 0, i < tam; i++){
            estado[i] = VAZIO;
        }
    }
    ~Dictionary();

    void insert(string key, E value);
    E remove(string key);
    E find(string key);
    void clear();
    int size();
    
};

int main(){
    return 0;
}