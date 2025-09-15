#include <stdio.h>
#include "lista_enc.h"

int main() {
    ListaEnc lista;
    len_init(&lista);

    printf("Inserindo no inicio:\n");
    len_push_front(&lista, 10);
    len_push_front(&lista, 20);
    len_push_front(&lista, 30);
    len_print(&lista);

    printf("Inserindo no final:\n");
    len_push_back(&lista, 40);
    len_push_back(&lista, 50);
    len_print(&lista);

    printf("Removendo valor 20:\n");
    len_remove_val(&lista, 20);
    len_print(&lista);

    printf("Removendo valor que nao existe (99):\n");
    len_remove_val(&lista, 99);
    len_print(&lista);

    len_clear(&lista);
    printf("Lista apos limpar:\n");
    len_print(&lista);

    return 0;
}
