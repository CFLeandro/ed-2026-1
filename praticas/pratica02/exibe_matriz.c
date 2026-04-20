#include <stdio.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    int matriz[LINHAS][COLUNAS];
    clock_t inicio, fim;
    double tempo_aninhado, tempo_unico;
    
    volatile int leitura; 

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = 0;
        }
    }

    printf("--- Analise de Percorrimento de Matriz 10x10 ---\n\n");

    // com dois laços 

    inicio = clock(); 
    
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            leitura = matriz[i][j]; 
        }
    }
    
    fim = clock(); 
    tempo_aninhado = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // com apenas um laço

    int total_elementos = LINHAS * COLUNAS; 
    
    inicio = clock(); 
    
    for (int k = 0; k < total_elementos; k++) {
        leitura = matriz[k / COLUNAS][k % COLUNAS]; 
    }
    
    fim = clock(); 
    tempo_unico = ((double)(fim - inicio)) / CLOCKS_PER_SEC;


    printf("Tempo com dois lacos aninhados: %f segundos\n", tempo_aninhado);
    printf("Tempo com apenas um laco:       %f segundos\n", tempo_unico);

    return 0;
}