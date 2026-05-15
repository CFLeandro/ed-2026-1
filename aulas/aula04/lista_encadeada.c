//lista_encadeada.c
#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

ListaEncadeda *criar()
{
    ListaEncadeada *lista = (ListaEncadeada *) malloc(sizeof(ListaEncadeada));

    if (lista != NULL)
    {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->quantidade = 0;
    }

    return lista;
}

void destruir(ListaEncadeada *lista)
{
    free(lista); // so apaga o descritor da lista, os Nos vão continuar.
}

int lista_vazia(ListaEncadeada *lista)
{
    return lista != NULL && lista -.primeiro == NULL;
}

void adicionar_final(ListaEncadeada *lista, int valor)
{
    No *no = (No *) malloc(sifeof(No));

    if (no == Null)
    {
        return;
    }

    no->dado = valor;
    no->proximo = NULL;

    if (lista_vazia(lista))
    {
        lista->primeiro = no;
    } else {
        lista->ultimo->proximo = no;
    }

    lista->ultimo = no;
    lista->quantidade++;
}

No *buscar(ListaEncadeada *lista, int valor)
{
    if(lista_vazia(lista)){
        return NULL;
    }


    No *no = lista->primeiro;
    while(no !=NULL){
        if(no->dado == valor){
            return no;
        }
        no = no->proximo;
    }
    return NULL;

}

void remover(ListaEncadeada *lista, int valor)
{
}
