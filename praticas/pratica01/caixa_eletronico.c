#include <stdio.h>

int main() {
    int saque;

    do {
        printf("Digite o valor do saque (Maximo de R$ 1000): ");
        scanf("%d", &saque);

        if (saque <= 0 || saque > 1000) {
            printf("Erro: O valor deve ser maior que 0 e no maximo 1000.\n\n");
        } 
        else if (saque == 1 || saque == 3) {
            printf("Erro: Nao e possivel sacar R$ %d pois a menor nota e R$ 2.\n\n", saque);
            saque = 0; 
        }
    } while (saque <= 0 || saque > 1000);

    printf("\n--- Notas para o saque de R$ %d ---\n", saque);

    int qtd_5 = 0;
    
    if (saque % 2 != 0) {
        qtd_5 = 1;
        saque -= 5;
    }

    int qtd_200 = saque / 200; 
    saque %= 200; 
    
    int qtd_100 = saque / 100; 
    saque %= 100;
    
    int qtd_50  = saque / 50;  
    saque %= 50;
    
    int qtd_20  = saque / 20;  
    saque %= 20;
    
    int qtd_10  = saque / 10;  
    saque %= 10;
    
    int qtd_2   = saque / 2;   
    saque %= 2; 

    if (qtd_200 > 0) printf("%d nota(s) de R$ 200\n", qtd_200);
    if (qtd_100 > 0) printf("%d nota(s) de R$ 100\n", qtd_100);
    if (qtd_50 > 0)  printf("%d nota(s) de R$ 50\n", qtd_50);
    if (qtd_20 > 0)  printf("%d nota(s) de R$ 20\n", qtd_20);
    if (qtd_10 > 0)  printf("%d nota(s) de R$ 10\n", qtd_10);
    if (qtd_5 > 0)   printf("%d nota(s) de R$ 5\n", qtd_5);
    if (qtd_2 > 0)   printf("%d nota(s) de R$ 2\n", qtd_2);

    return 0;
}