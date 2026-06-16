#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore minha_arvore = arvore_criar();
    if (minha_arvore == NULL) {
        printf("Erro ao inicializar a arvore.\n");
        return 1;
    }

    printf("--- Teste de TDA Arvore Binaria de Busca ---\n");
    printf("Arvore esta vazia? %s\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");

    printf("\nInserindo elementos: 50, 30, 70, 20, 40, 60, 80\n");
    arvore_inserir(minha_arvore, 50);
    arvore_inserir(minha_arvore, 30);
    arvore_inserir(minha_arvore, 70);
    arvore_inserir(minha_arvore, 20);
    arvore_inserir(minha_arvore, 40);
    arvore_inserir(minha_arvore, 60);
    arvore_inserir(minha_arvore, 80);

    printf("Arvore esta vazia? %s\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");

    printf("\nExibicao em Pre-Ordem (Raiz-Esq-Dir):\n");
    arvore_exibir_pre_ordem(minha_arvore);

    printf("\nExibicao em Em-Ordem (Esq-Raiz-Dir -> Ordenado):\n");
    arvore_exibir_em_ordem(minha_arvore);

    printf("\nExibicao em Pos-Ordem (Esq-Dir-Raiz):\n");
    arvore_exibir_pos_ordem(minha_arvore);

    printf("\nDestruindo a arvore e liberando memoria...\n");
    arvore_destruir(minha_arvore);

    printf("Testes concluidos com sucesso.\n");
    return 0;
}