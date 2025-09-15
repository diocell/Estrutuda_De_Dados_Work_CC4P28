#include <stdio.h>
#include "lista_enc.h"


void len_init(ListaEnc *L) {
    L->inicio = NULO;
    L->tamanho = 0;
    L->livre = 0;

    // inicializa a lista de nós livres
    for (int i = 0; i < CAP - 1; i++)
        L->nos[i].prox = i + 1;
    L->nos[CAP - 1].prox = NULO;
}

// Inserir no início
int len_push_front(ListaEnc *L, int v) {
    if (L->livre == NULO) return 0; // lista cheia

    int novo = L->livre;             // pega nó livre
    L->livre = L->nos[novo].prox;    // atualiza próximo nó livre

    L->nos[novo].valor = v;
    L->nos[novo].prox = L->inicio;
    L->inicio = novo;

    L->tamanho++;
    return 1;
}

// Inserir no final
int len_push_back(ListaEnc *L, int v) {
    if (L->livre == NULO) return 0; // lista cheia

    int novo = L->livre;
    L->livre = L->nos[novo].prox;

    L->nos[novo].valor = v;
    L->nos[novo].prox = NULO;

    if (L->inicio == NULO) {
        L->inicio = novo;
    } else {
        int i = L->inicio;
        while (L->nos[i].prox != NULO)
            i = L->nos[i].prox;
        L->nos[i].prox = novo;
    }

    L->tamanho++;
    return 1;
}

// Remover a primeira ocorrência
int len_remove_val(ListaEnc *L, int v) {
    if (L->inicio == NULO) return 0;

    int prev = NULO;
    int i = L->inicio;
    while (i != NULO) {
        if (L->nos[i].valor == v) {
            if (prev == NULO) {
                L->inicio = L->nos[i].prox;
            } else {
                L->nos[prev].prox = L->nos[i].prox;
            }

            // devolve nó ao índice livre
            L->nos[i].prox = L->livre;
            L->livre = i;

            L->tamanho--;
            return 1;
        }
        prev = i;
        i = L->nos[i].prox;
    }
    return 0; // não encontrado
}

// Buscar índice do valor
int len_index_of(const ListaEnc *L, int valor) {
    int idx = 0;
    int i = L->inicio;
    while (i != NULO) {
        if (L->nos[i].valor == valor)
            return idx;
        i = L->nos[i].prox;
        idx++;
    }
    return NULO;
}

// Imprimir lista
void len_print(const ListaEnc *L) {
    int i = L->inicio;
    printf("[");
    while (i != NULO) {
        printf("%d", L->nos[i].valor);
        if (L->nos[i].prox != NULO) printf(" -> ");
        i = L->nos[i].prox;
    }
    printf("]\n");
}

// Limpar lista
void len_clear(ListaEnc *L) {
    L->inicio = NULO;
    L->tamanho = 0;
    L->livre = 0;
    for (int i = 0; i < CAP - 1; i++)
        L->nos[i].prox = i + 1;
    L->nos[CAP - 1].prox = NULO;
}
