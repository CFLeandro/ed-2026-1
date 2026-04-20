#include <stdio.h>

#define TAM 100 

int main() {
    int vetor[TAM];
    int chave;
    int posicao = -1; 

    printf("--- Preenchimento do Vetor ---\n");
    for (int i = 0; i < TAM; i++) {
        printf("Digite o valor da posicao %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite o valor que deseja buscar no vetor: ");
    scanf("%d", &chave);

    for (int i = 0; i < TAM; i++) {
        if (vetor[i] == chave) {
            posicao = i; 
            break;       
        }
    }

    if (posicao != -1) {
        printf("\nResultado: O valor %d foi encontrado na posicao %d do vetor (indice %d).\n", chave, posicao + 1, posicao);
    } else {
        printf("\nResultado: O valor %d nao existe no vetor informado.\n", chave);
    }

    return 0;
}