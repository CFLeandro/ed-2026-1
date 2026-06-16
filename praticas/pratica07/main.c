#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha minha_pilha = pilha_criar();
    if (minha_pilha == NULL) {
        printf("Erro ao inicializar a pilha.\n");
        return 1;
    }

    printf("--- Teste de TDA Pilha ---\n");
    printf("Pilha esta vazia? %s\n", pilha_esta_vazia(minha_pilha) ? "Sim" : "Nao");

    printf("\nEmpilhando: 10, 20, 30\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);

    printf("Estado atual da ");
    pilha_exibir(minha_pilha);

    printf("\nElemento no topo atual: %d\n", pilha_topo(minha_pilha));

    printf("\nDesempilhando um elemento: %d\n", pilha_desempilhar(minha_pilha));
    printf("Estado da ");
    pilha_exibir(minha_pilha);
    
    printf("Novo topo: %d\n", pilha_topo(minha_pilha));

    printf("\nDesempilhando outro elemento: %d\n", pilha_desempilhar(minha_pilha));
    printf("Estado da ");
    pilha_exibir(minha_pilha);

    printf("\nDestruindo a pilha e liberando memoria...\n");
    pilha_destruir(minha_pilha);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}