#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
} no_t;

typedef struct lista_t {
    no_t* primeiro;
    no_t* ultimo;
} lista_t;

Lista lista_criar() {
    Lista l = (Lista)malloc(sizeof(lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

int lista_esta_vazia(Lista l) {
    if (l == NULL) return 1;
    return (l->primeiro == NULL);
}

int lista_inserir(Lista l, int valor) {
    if (l == NULL) return 0;

    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo == NULL) return 0; 

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = l->ultimo;

    if (lista_esta_vazia(l)) {
        l->primeiro = novo; 
    } else {
        l->ultimo->proximo = novo;
    }
    
    l->ultimo = novo; 
    return 1;
}

int lista_buscar(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;

    no_t* atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0; 
}

int lista_remover(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return 0;

    no_t* atual = l->primeiro;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return 0; 

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        l->primeiro = atual->proximo; 
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        l->ultimo = atual->anterior; 
    }

    free(atual);
    return 1;
}

void lista_exibir(Lista l) {
    if (l == NULL || lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }

    no_t* atual = l->primeiro;
    printf("[ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

void lista_destruir(Lista l) {
    if (l == NULL) return;

    no_t* atual = l->primeiro;
    while (atual != NULL) {
        no_t* prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    free(l);
}
