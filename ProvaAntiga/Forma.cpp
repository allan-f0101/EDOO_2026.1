#include "Forma.h"

double Triangulo::area() const{
    return (base * altura) / 2;
}

double Quadrado::area() const{
    return lado * lado;
}