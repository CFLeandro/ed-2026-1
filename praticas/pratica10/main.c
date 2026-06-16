#include <stdio.h>
#include "tabela_hash.h"

int main() {
    int tamanho_tabela = 7;
    TabelaHash minha_hash = hash_criar(tamanho_tabela);
    
    if (minha_hash == NULL) {
        printf("Erro ao inicializar a tabela hash.\n");
        return 1;
    }

    printf("Tabela hash criada com tamanho %d.\n", tamanho_tabela);
    printf("Tabela esta vazia? %s\n", hash_esta_vazia(minha_hash) ? "Sim" : "Nao");

    printf("\nInserindo valores: 15, 8, 22, 4, 20, 13, 35\n");
    hash_inserir(minha_hash, 15);
    hash_inserir(minha_hash, 8);
    hash_inserir(minha_hash, 22);
    hash_inserir(minha_hash, 4);
    hash_inserir(minha_hash, 20);
    hash_inserir(minha_hash, 13);
    hash_inserir(minha_hash, 35);

    hash_exibir(minha_hash);
    printf("Tabela esta vazia? %s\n", hash_esta_vazia(minha_hash) ? "Sim" : "Nao");

    printf("\nBuscando valor 8: %s\n", hash_buscar(minha_hash, 8) ? "Encontrado!" : "Nao encontrado.");
    printf("Buscando valor 99: %s\n", hash_buscar(minha_hash, 99) ? "Encontrado!" : "Nao encontrado.");

    printf("\nRemovendo o valor 8 (elemento do meio/fim de uma colisao):\n");
    if (hash_remover(minha_hash, 8)) {
        printf("Valor 8 removido com sucesso.\n");
    }
    
    printf("Removendo o valor 13 (elemento do topo/inicio de uma colisao):\n");
    if (hash_remover(minha_hash, 13)) {
        printf("Valor 13 removido com sucesso.\n");
    }

    hash_exibir(minha_hash);

    printf("\nDestruindo a tabela hash e limpando memoria...\n");
    hash_destruir(minha_hash);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}