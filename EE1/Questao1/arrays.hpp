#ifndef ARRAYS_H
#define ARRAYS_H

#include "excecao.hpp"
#include <iostream>

template<typename T>
class ArrayGen{
private:
    int size;
    T* array;

public:
    ArrayGen(int n, T v) : size(n){
        array = new T[n];
        for(int i = 0; i < n; i++){
            array[i] = v;
        }
    }

    ~ArrayGen(){
        delete[] array;
    }

    T get_elem(int valor){
        if(valor < 0 || valor >= size){
            throw IndexOutOfBounds(valor);
        }
        return array[valor];
    }

    void set_elem(int chave, T valor){
        if(chave < 0 || chave >= size){
            throw IndexOutOfBounds(chave);
        }
        array[chave] = valor;
    }

    int get_size() const {return size;}

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const ArrayGen<U>& a);
    
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const ArrayGen<T>& a){
    os << "{";
    for(int i = 0; i < a.size; i++){
        os << a.array[i];
        if(i < a.size - 1) os << ", ";
    }
    os << "}";
    return os;
}

#endif