#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <iostream>
#include "pacote.h"

class Dispositivo{
protected:
    std::string IP;
    std::string nome;

public:
    Dispositivo(std::string ip, std::string n) : IP(ip), nome(n) {}
    virtual ~Dispositivo(){}

    std::string get_ip() const{
        return IP;
    }

    std::string get_nome() const{
        return nome;
    }

    virtual void processarPacote(Pacote p) = 0;

};

#endif