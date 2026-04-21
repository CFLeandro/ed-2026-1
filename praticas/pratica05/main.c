#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 100

/* Função para duplicar o vetor e garantir testes justos */
void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int vetor_original[TAMANHO];
    int vetor_copia[TAMANHO];
    clock_t inicio, fim;
    double tempo_gasto;

    // Inicializa o gerador de números aleatórios
    srand((unsigned int)time(NULL));

    // Gera o vetor original com 100 números aleatórios entre 0 e 999
    for (int i = 0; i < TAMANHO; i++) {
        vetor_original[i] = rand() % 1000;
    }

    printf("=== Algoritmos de Busca/Selecao (%d elementos) ===\n\n", TAMANHO);

    // TESTE 1: LINEAR SEARCH
    int chave_para_buscar = vetor_original[TAMANHO - 15]; 
    
    inicio = clock();
    int indice_encontrado = linear_search(vetor_original, TAMANHO, chave_para_buscar);
    fim = clock();
    
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("--- Linear Search ---\n");
    printf("Objetivo: Encontrar o indice do valor %d.\n", chave_para_buscar);
    printf("Resultado: Encontrado no indice %d.\n", indice_encontrado);
    printf("Tempo Execucao: %f segundos\n\n", tempo_gasto);

    // TESTE 2: QUICK SELECT
    int k = 50;
    copiar_vetor(vetor_original, vetor_copia, TAMANHO); 
    
    inicio = clock();
    int k_esimo_menor = quick_select(vetor_copia, 0, TAMANHO - 1, k);
    fim = clock();
    
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("--- Quick Select ---\n");
    printf("Objetivo: Encontrar o %d-esimo menor elemento.\n", k);
    printf("Resultado: O valor e %d.\n", k_esimo_menor);
    printf("Tempo Execucao: %f segundos\n\n", tempo_gasto);

    return 0;
}