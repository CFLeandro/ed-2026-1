#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // ligou o cronometro
    clock_t tempo_inicial = clock();

    int soma = 10 + 20; // 0(1)

    clock_t tempo_final = clock();
    //desliguei o cronometro

    double duracao = (double) (tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.5f seg\n", duracao);

    tempo_inicial = clock();

    for (int i = 0; i<10000; i++) {
        soma = soma + 1;
    }

    tempo_final = clock();

    double duracao2 = (double) (tempo_final - tempo_inicial) / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.5f seg\n", duracao2);

    return 0;
}