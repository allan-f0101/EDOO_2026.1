#include <iostream>
#include "Forma.h"

using namespace std;

int main(){
    Quadrado q(50);
    Triangulo t(10, 20);

    cout << "A área do Triângulo é " << t.area() << endl;
    cout << "A área do Quadrado é " << q.area() << endl;
    return 0;
}