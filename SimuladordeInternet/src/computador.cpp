#include <iostream>
#include "../include/computador.h"

Computador::Computador(std::string ip, std::string n) : Dispositivo(ip, n){}

void Computador::processarPacote(Pacote p){
    std::cout << "[" << nome << " (" << IP << ")] Pacote final recebido!" << std::endl;
    std::cout << "Conteudo da mensagem: " << p.mensagem << std::endl;
}
