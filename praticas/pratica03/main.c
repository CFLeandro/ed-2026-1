#include <stdio.h>
#include "conta.h"

int main() {
    printf("=== Teste do TDA Conta Bancaria ===\n\n");

    Conta minha_conta = conta_criar(102030, 500.00);
    if (minha_conta == NULL) {
        printf("Erro ao alocar memoria para a conta.\n");
        return 1;
    }
    printf("Conta criada com sucesso!\n");
    printf("Saldo inicial: R$ %.2f\n", conta_ver_saldo(minha_conta));

    printf("\n--- Operacao: Deposito ---\n");
    if (conta_depositar(minha_conta, 250.50)) {
        printf("Deposito de R$ 250.50 realizado.\n");
    }
    printf("Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));

    printf("\n--- Operacao: Saque ---\n");
    if (conta_sacar(minha_conta, 100.00)) {
        printf("Saque de R$ 100.00 realizado.\n");
    }
    printf("Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));

    printf("\n--- Operacao: Saque (Acima do saldo) ---\n");
    if (!conta_sacar(minha_conta, 1000.00)) {
        printf("Falha: Saldo insuficiente para sacar R$ 1000.00.\n");
    }
    printf("Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));

    conta_destruir(minha_conta);
    printf("\nConta encerrada e memoria liberada com sucesso.\n");

    return 0;
}