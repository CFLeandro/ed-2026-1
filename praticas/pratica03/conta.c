#include <stdlib.h>
#include <stdio.h>
#include "conta.h"

struct conta_t {
    int numero;
    double saldo;
};

Conta conta_criar(int numero, double saldo_inicial) {
    Conta c = (Conta) malloc(sizeof(struct conta_t));
    
    if (c != NULL) {
        c->numero = numero;
        c->saldo = (saldo_inicial > 0) ? saldo_inicial : 0.0;
    }
    
    return c;
}

int conta_depositar(Conta c, double valor) {
    if (c == NULL || valor <= 0.0) {
        return 0; 
    }
    
    c->saldo += valor;
    return 1; 
}

int conta_sacar(Conta c, double valor) {
    if (c == NULL || valor <= 0.0 || c->saldo < valor) {
        return 0; 
    }
    
    c->saldo -= valor;
    return 1; 
}

double conta_ver_saldo(Conta c) {
    if (c == NULL) {
        return -1.0; 
    }
    return c->saldo;
}

void conta_destruir(Conta c) {
    if (c != NULL) {
        free(c); 
    }
}