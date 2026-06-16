#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t* esquerda;
    struct no_t* direita;
} no_t;

typedef struct arvore_t {
    no_t* raiz;
} arvore_t;

static no_t* criar_no(int valor) {
    no_t* novo = (no_t*)malloc(sizeof(no_t));
    if (novo != NULL) {
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

Arvore arvore_criar() {
    Arvore a = (Arvore)malloc(sizeof(arvore_t));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

int arvore_esta_vazia(Arvore a) {
    if (a == NULL) return 1;
    return (a->raiz == NULL);
}

static no_t* inserir_recursivo(no_t* raiz, int valor, int* sucesso) {
    if (raiz == NULL) {
        no_t* novo = criar_no(valor);
        if (novo != NULL) *sucesso = 1;
        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_recursivo(raiz->esquerda, valor, sucesso);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_recursivo(raiz->direita, valor, sucesso);
    } else {
        *sucesso = 0; 
    }
    return raiz;
}

int arvore_inserir(Arvore a, int valor) {
    if (a == NULL) return 0;
    int sucesso = 0;
    a->raiz = inserir_recursivo(a->raiz, valor, &sucesso);
    return sucesso;
}

static void pre_ordem_recursivo(no_t* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem_recursivo(raiz->esquerda);
        pre_ordem_recursivo(raiz->direita);
    }
}

void arvore_exibir_pre_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) return;
    pre_ordem_recursivo(a->raiz);
    printf("\n");
}

static void em_ordem_recursivo(no_t* raiz) {
    if (raiz != NULL) {
        em_ordem_recursivo(raiz->esquerda);
        printf("%d ", raiz->valor);
        em_ordem_recursivo(raiz->direita);
    }
}

void arvore_exibir_em_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) return;
    em_ordem_recursivo(a->raiz);
    printf("\n");
}

static void pos_ordem_recursivo(no_t* raiz) {
    if (raiz != NULL) {
        pos_ordem_recursivo(raiz->esquerda);
        pos_ordem_recursivo(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void arvore_exibir_pos_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) return;
    pos_ordem_recursivo(a->raiz);
    printf("\n");
}

static void destruir_nos(no_t* raiz) {
    if (raiz == NULL) return;
    destruir_nos(raiz->esquerda);
    destruir_nos(raiz->direita);
    free(raiz); 
}

void arvore_destruir(Arvore a) {
    if (a == NULL) return;
    destruir_nos(a->raiz);
    free(a);
}