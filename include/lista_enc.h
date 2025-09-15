// lista_enc.h
#ifndef LISTA_ENC_H
#define LISTA_ENC_H

#define CAP 100
#define NULO -1

typedef struct {
    int valor;
    int prox;
} No;

typedef struct {
    No nos[CAP];
    int inicio;
    int tamanho;
    int livre;
} ListaEnc;

void len_init(ListaEnc *L);
int len_push_front(ListaEnc *L, int v);
int len_push_back(ListaEnc *L, int v);
int len_remove_val(ListaEnc *L, int v);
void len_print(const ListaEnc *L);
void len_clear(ListaEnc *L);
int len_index_of(const ListaEnc *L, int valor);

#endif
