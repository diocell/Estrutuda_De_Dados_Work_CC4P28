// lista_seq.h
#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

#define CAP 100

typedef struct {
    int dados[CAP];
    int tamanho;
} ListaSeq;

void lsq_init(ListaSeq *L);
int lsq_push_back(ListaSeq *L, int x);
int lsq_insert(ListaSeq *L, int i, int x);
int lsq_remove_at(ListaSeq *L, int i);
int lsq_index_of(const ListaSeq *L, int x);
void lsq_print(const ListaSeq *L);

#endif
