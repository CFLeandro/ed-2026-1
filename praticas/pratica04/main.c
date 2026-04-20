#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 100

void copiar_vetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int vetor_original[TAMANHO];
    int vetor_teste[TAMANHO];
    clock_t inicio, fim;
    double tempo_gasto;

    srand(time(NULL));

    for (int i = 0; i < TAMANHO; i++) {
        vetor_original[i] = rand() % 1000; 
    }

    printf("=== Teste de Algoritmos de Ordenacao (%d elementos) ===\n\n", TAMANHO);

    copiar_vetor(vetor_original, vetor_teste, TAMANHO);
    inicio = clock();
    bubble_sort(vetor_teste, TAMANHO);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do Bubble Sort:    %f segundos\n", tempo_gasto);

    copiar_vetor(vetor_original, vetor_teste, TAMANHO);
    inicio = clock();
    selection_sort(vetor_teste, TAMANHO);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do Selection Sort: %f segundos\n", tempo_gasto);

    copiar_vetor(vetor_original, vetor_teste, TAMANHO);
    inicio = clock();
    quick_sort(vetor_teste, 0, TAMANHO - 1);
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do Quick Sort:     %f segundos\n", tempo_gasto);

    return 0;
}