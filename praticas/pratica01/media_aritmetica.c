#include <stdio.h>

int main() {
    int n;
    double numero;
    double soma = 0.0;
    double media;

    do {
        printf("Quantos numeros voce deseja informar? (Maximo de 100): ");
        scanf("%d", &n);

        if (n <= 0 || n > 100) {
            printf("Erro: O valor deve ser maior que 0 e no maximo 100.\n\n");
        }
    } while (n <= 0 || n > 100);

    for (int i = 0; i < n; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%lf", &numero);

        soma += numero; 
    }

    media = soma / n;

    printf("\n--- Resultado ---\n");
    printf("A media aritmetica dos %d numeros informados e: %.2lf\n", n, media);

    return 0;
}