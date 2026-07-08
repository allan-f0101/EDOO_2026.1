#ifndef EQUIPC_H
#define EQUIPC_H

#include <iostream>
#include <vector>
#include "Equip.hpp"

class EquipC : public Equip{
private:
    std::vector<Equip*> equips;

public:
    EquipC(std::string d) : Equip(d){}
    ~EquipC(){}

    void add(Equip* e){
        equips.push_back(e);
    }

    double get_preco() override{
        double soma = 0.0;
        
        for(int i = 0; i < equips.size(); i++){
            soma += equips[i]->get_preco();
        }
        return soma;
    }
};

#endif