#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main() {
    Agenda agenda = criar_agenda(10);

    Contato contato;
    strcpy(contato.nome, "Pedrao Assombracao");
    strcpy(contato.telefone, "4200-2407");

    adicionar_contato(&agenda, contato);

    Contato outro;
    strcpy(outro.nome, "MauMau Assombracao");
    strcpy(outro.telefone, "7259-5429");

    adicionar_contato(&agenda, outro);

    listar_contato(&agenda);

    return 0;
}