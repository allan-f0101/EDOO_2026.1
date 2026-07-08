#include <iostream>
#include "../include/pacote.h"
#include "../include/computador.h"

int main(){
    Computador meuPC("192.168.1.5", "Servidor_Web");
    Pacote p;
    p.remetente = "192.168.1.100";
    p.destinatario = "192.168.1.5";
    p.mensagem = "Requisicao de login aceita";
    p.identificador = 1;

    meuPC.processarPacote(p);
}