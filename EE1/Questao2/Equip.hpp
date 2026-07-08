#ifndef EQUIP_H
#define EQUIP_H

#include <iostream>

class Equip{
private:
    std::string desc;

public:
    Equip(std::string d) : desc(d){}
    virtual ~Equip(){}

    std::string get_desc(){
        return desc;
    }

    virtual double get_preco() = 0;
};

#endif