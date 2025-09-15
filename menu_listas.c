#include <stdio.h>
#include <stdlib.h>
#include "lista_seq.h"
#include "lista_enc.h"

int main() {
    ListaSeq listaSeq;
    ListaEnc listaEnc;
    int usandoSeq = 1; // por padrão começa SEMPRE na sequencial
    int opcao, valor, pos;

    lsq_init(&listaSeq);
    len_init(&listaEnc);

    do {
        printf("\n=== MENU LISTAS ===\n");
        printf("1. Usar Lista Sequencial\n");
        printf("2. Usar Lista Encadeada\n");
        printf("3. Inserir\n");
        printf("4. Remover\n");
        printf("5. Buscar\n");
        printf("6. Imprimir\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                usandoSeq = 1;
                printf(">> Agora usando Lista Sequencial.\n");
                break;
            case 2:
                usandoSeq = 0;
                printf(">> Agora usando Lista Encadeada.\n");
                break;
            case 3: // Inserir
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (usandoSeq) {
                    printf("1. Inserir no final\n2. Inserir em posicao especifica\nEscolha: ");
                    int modo; scanf("%d", &modo);
                    if (modo == 1) {
                        if (lsq_push_back(&listaSeq, valor))
                            printf("Inserido com sucesso!\n");
                        else
                            printf("Erro: lista cheia.\n");
                    } else {
                        printf("Digite a posicao: ");
                        scanf("%d", &pos);
                        if (lsq_insert(&listaSeq, pos, valor))
                            printf("Inserido com sucesso!\n");
                        else
                            printf("Erro: posicao invalida ou lista cheia.\n");
                    }
                } else {
                    printf("1. Inserir no inicio\n2. Inserir no final\nEscolha: ");
                    int modo; scanf("%d", &modo);
                    if (modo == 1) len_push_front(&listaEnc, valor);
                    else len_push_back(&listaEnc, valor);
                    printf("Inserido com sucesso!\n");
                }
                break;
            case 4: // Remover
                if (usandoSeq) {
                    printf("Digite a posicao para remover: ");
                    scanf("%d", &pos);
                    if (lsq_remove_at(&listaSeq, pos))
                        printf("Removido com sucesso!\n");
                    else
                        printf("Erro: posicao invalida.\n");
                } else {
                    printf("Digite o valor para remover: ");
                    scanf("%d", &valor);
                    if (len_remove_val(&listaEnc, valor))
                        printf("Removido com sucesso!\n");
                    else
                        printf("Erro: valor nao encontrado.\n");
                }
                break;
            case 5: // Buscar
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                if (usandoSeq) {
                    int idx = lsq_index_of(&listaSeq, valor);
                    if (idx >= 0)
                        printf("Valor encontrado na posicao %d.\n", idx);
                    else
                        printf("Valor nao encontrado.\n");
                } else {
                    int pos = len_index_of(&listaEnc, valor);
                    if (pos != NULO)
                        printf("Valor encontrado na posicao %d.\n", pos);
                    else
                        printf("Valor nao encontrado.\n");
                }
                break;
            case 6: // Imprimir
                if (usandoSeq) lsq_print(&listaSeq);
                else len_print(&listaEnc);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    len_clear(&listaEnc); // libera memória antes de sair
    return 0;
}
