#include <stdio.h>
#include "fila.h"

int main() {
    Fila minha_fila = fila_criar();
    if (minha_fila == NULL) {
        printf("Erro ao inicializar a fila.\n");
        return 1;
    }

    printf("--- Teste de TDA Fila ---\n");
    printf("Fila esta vazia? %s\n", fila_esta_vazia(minha_fila) ? "Sim" : "Nao");

    printf("\nEnfileirando elementos: 10, 20, 30, 40\n");
    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    fila_enfileirar(minha_fila, 40);

    printf("Estado atual da ");
    fila_exibir(minha_fila);
    printf("Fila esta vazia? %s\n", fila_esta_vazia(minha_fila) ? "Sim" : "Nao");

    printf("\nElemento no inicio atual: %d\n", fila_inicio(minha_fila));

    printf("\nDesenfileirando um elemento (deve ser o 10): %d\n", fila_desenfileirar(minha_fila));
    printf("Estado da ");
    fila_exibir(minha_fila);

    printf("Novo elemento no inicio: %d\n", fila_inicio(minha_fila));

    printf("\nDesenfileirando outro elemento (deve ser o 20): %d\n", fila_desenfileirar(minha_fila));
    printf("Estado da ");
    fila_exibir(minha_fila);

    printf("\nDestruindo a fila e liberando memoria...\n");
    fila_destruir(minha_fila);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}