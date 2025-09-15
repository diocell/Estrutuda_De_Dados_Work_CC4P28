#include <stdio.h>
#include "lista_seq.h"

void lsq_init(ListaSeq *L) {
    L->tamanho = 0;
}

int lsq_push_back(ListaSeq *L, int x) {
    if (L->tamanho >= CAP) return 0;
    L->dados[L->tamanho] = x;
    L->tamanho++;
    return 1;
}

int lsq_insert(ListaSeq *L, int i, int x) {
    if (L->tamanho >= CAP || i < 0 || i > L->tamanho) return 0;
    for (int j = L->tamanho; j > i; j--) {
        L->dados[j] = L->dados[j - 1];
    }
    L->dados[i] = x;
    L->tamanho++;
    return 1;
}

int lsq_remove_at(ListaSeq *L, int i) {
    if (i < 0 || i >= L->tamanho) return 0;
    for (int j = i; j < L->tamanho - 1; j++) {
        L->dados[j] = L->dados[j + 1];
    }
    L->tamanho--;
    return 1;
}

int lsq_index_of(const ListaSeq *L, int x) {
    for (int i = 0; i < L->tamanho; i++) {
        if (L->dados[i] == x) return i;
    }
    return -1;
}

void lsq_print(const ListaSeq *L) {
    printf("[");
    for (int i = 0; i < L->tamanho; i++) {
        printf("%d", L->dados[i]);
        if (i < L->tamanho - 1) printf(", ");
    }
    printf("]\n");
}

int lsq_remove_val(ListaSeq *L, int x) {
    for (int i = 0; i < L->tamanho; i++) {
        if (L->dados[i] == x) {
            for (int j = i; j < L->tamanho - 1; j++) {
                L->dados[j] = L->dados[j + 1];
            }
            L->tamanho--;
            return 1;
        }
    }
    return 0;
}
