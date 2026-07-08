#include <iostream>
#include "excecao.hpp"
#include "arrays.hpp"

using namespace std;

int main(){
    ArrayGen<int> A(5, -1);

    A.set_elem(2, 10);
    cout << "Conteudo de A: " << A << std::endl;

    try{
        A.set_elem(5, 10);
    }
    catch(const IndexOutOfBounds& e){
        std::cout << "Capturado: " << e.get_errormsg() << std::endl;
    }
    
    return 0;
}