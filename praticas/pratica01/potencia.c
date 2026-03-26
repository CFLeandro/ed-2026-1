#include <stdio.h>

int main() {
    double base;
    int expoente;
    double resultado = 1.0;

    printf("Digite o valor da base: ");
    scanf("%lf", &base);

    printf("Digite o valor do expoente (inteiro e positivo): ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("Erro: Por favor, insira um expoente inteiro positivo ou zero.\n");
        return 1; 
    }

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    printf("%.2lf elevado a %d é igual a: %.2lf\n", base, expoente, resultado);

    return 0;
}