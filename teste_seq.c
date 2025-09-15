#include <stdio.h>
#include "lista_seq.h"

int main() {
    ListaSeq lista;
    lsq_init(&lista);

    printf("Inserindo elementos no final:\n");
    lsq_push_back(&lista, 10);
    lsq_push_back(&lista, 20);
    lsq_push_back(&lista, 30);
    lsq_print(&lista);

    printf("Inserindo na posicao 1 (valor 15):\n");
    lsq_insert(&lista, 1, 15);
    lsq_print(&lista);

    printf("Removendo na posicao 2:\n");
    lsq_remove_at(&lista, 2);
    lsq_print(&lista);

    printf("Indice do valor 20: %d\n", lsq_index_of(&lista, 20));
    printf("Indice do valor 99: %d\n", lsq_index_of(&lista, 99));

    return 0;
}
