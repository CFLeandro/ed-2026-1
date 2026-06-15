#include <stdio.h>
#include "lista_linear.h"

int main() {
    Lista minha_lista = lista_criar();
    if (minha_lista == NULL) {
        printf("Erro ao inicializar a lista.\n");
        return 1;
    }

    printf("--- Teste de Lista Linear Duplamente Encadeada ---\n");
    printf("Lista esta vazia? %s\n", lista_esta_vazia(minha_lista) ? "Sim" : "Nao");

    printf("\nInserindo elementos: 10, 20, 30, 40\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    
    printf("Estado atual da ");
    lista_exibir(minha_lista);
    printf("Lista esta vazia? %s\n", lista_esta_vazia(minha_lista) ? "Sim" : "Nao");

    printf("\nBuscando pelo valor 30: %s\n", lista_buscar(minha_lista, 30) ? "Encontrado" : "Nao encontrado");
    printf("Buscando pelo valor 99: %s\n", lista_buscar(minha_lista, 99) ? "Encontrado" : "Nao encontrado");

    printf("\nRemovendo valor do meio (30):\n");
    lista_remover(minha_lista, 30);
    lista_exibir(minha_lista);

    printf("Removendo valor do inicio (10):\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    printf("Removendo valor do fim (40):\n");
    lista_remover(minha_lista, 40);
    lista_exibir(minha_lista);

    printf("\nDestruindo a lista e liberando memoria...\n");
    lista_destruir(minha_lista);
    
    printf("Testes concluidos com sucesso.\n");
    return 0;
}