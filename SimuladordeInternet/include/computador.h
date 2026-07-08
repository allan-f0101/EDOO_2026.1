#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include <iostream>
#include "dispositivo.h"

class Computador : public Dispositivo{
public:
    Computador(std::string ip, std::string n);

    void processarPacote(Pacote p) override;
};

#endif