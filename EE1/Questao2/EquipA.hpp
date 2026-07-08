#ifndef EQUIPA_H
#define EQUIPA_H

#include <iostream>
#include "Equip.hpp"

class EquipA : public Equip{
private:
    double preco;

public:
    EquipA(std::string d, double p) : preco(p), Equip(d){}
    ~EquipA(){}

    double get_preco() override{
        return preco;
    }

};

#endif