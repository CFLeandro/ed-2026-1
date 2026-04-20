#include <stdio.h>

unsigned long long fatorial_iterativo(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

unsigned long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int numero;

    do {
        printf("Digite um numero inteiro positivo para calcular o fatorial: ");
        scanf("%d", &numero);

        if (numero < 0) {
            printf("Erro: O fatorial nao e definido para numeros negativos.\n\n");
        }
    } while (numero < 0);

    unsigned long long resultado_iterativo = fatorial_iterativo(numero);
    unsigned long long resultado_recursivo = fatorial_recursivo(numero);

    printf("\n--- Resultados para %d! ---\n", numero);
    printf("Metodo Iterativo (Repeticao): %llu\n", resultado_iterativo);
    printf("Metodo Recursivo:             %llu\n", resultado_recursivo);

    return 0;
}