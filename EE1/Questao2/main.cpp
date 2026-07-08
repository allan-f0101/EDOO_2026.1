#include "Equip.hpp"
#include "EquipC.hpp"
#include "EquipA.hpp"
#include <iostream>

using namespace std;

int main(){
    EquipA ea1("Equipamento Atômico 1", 12.5);
    EquipA ea2("Equipamento Atômico 2", 13.5);

    EquipC ec1("Equipamento Composto 1");

    ec1.add(&ea1);
    ec1.add(&ea2);

    cout << "Preco ea1: R$ " << ea1.get_preco() << endl;
    cout << "Preco ec1 (Composto): R$ " << ec1.get_preco() << endl;
    return 0;
}