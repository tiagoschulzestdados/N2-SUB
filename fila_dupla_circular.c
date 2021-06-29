#include <stdio.h>
#include <stdlib.h>


struct no {
    int info;
    struct no* elo_prox;
    struct no* elo_ant;
};
typedef struct no No;

struct fila {
    No* inicio;
    No* fim;
};
typedef struct fila Fila;


No* inicio;
No* fim;


Fila* cria() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}


/* MEU CODIGO */

No* insere_fim(No* inicio, No* fim, int info) {
    No* no = (No*)malloc(sizeof(No));
    no->info = info;

    if (inicio == NULL) {
        no->elo_ant = no;
        no->elo_prox = no;
    }
    else {
        no->elo_ant = fim;
        no->elo_prox = inicio;
        fim = no;
    }
    return no;
}


void adiciona_fim_fila(Fila* fila, int info) {
    fila->fim = insere_fim(fila->inicio, fila->fim, info);

    if (fila->inicio == NULL) {
        fila->inicio = fila->fim;
    }
    else {
        fila->inicio->elo_ant = fila->fim;
        fila->fim->elo_ant->elo_prox = fila->fim;
    }
}


No* insere_inicio(No* inicio, No* fim, int info) {
    No* no = (No*)malloc(sizeof(No));
    no->info = info;

    if (inicio == NULL) {
        no->elo_ant = no;
        no->elo_prox = no;
    }
    else {
        no->elo_ant = fim;
        fim = no;
        no->elo_prox = inicio;
    }
    return no;
}


void adiciona_inicio_fila(Fila* fila, int info) {
    fila->inicio = insere_inicio(fila->inicio, fila->fim, info);

    if (fila->inicio == NULL) {
        fila->inicio = fila->fim;
    }
    else {
        fila->fim->elo_prox = fila->inicio->elo_prox->elo_ant = fila->inicio;
    }
}



void retira_inicio(Fila* fila) {
    No* no = fila->inicio->elo_prox;
    free(fila->inicio);

    fila->inicio = no;
    fila->inicio->elo_prox->elo_ant = fila->fim->elo_prox = fila->inicio;
    fila->inicio->elo_ant = fila->fim;
}


void retira_fim(Fila* fila) {
    No* no = fila->fim->elo_ant;
    free(fila->fim);

    fila->fim = fila->inicio->elo_ant = no;
    fila->fim->elo_prox = fila->inicio;

    no = NULL;
}



void imprime_fila(Fila* fila) {
    No* no;
    printf("\n");
    printf("\nFILA: %p\n\n INICIO....: %p\n FIM.......: %p\n\n", fila, fila->inicio, fila->fim);
    no = fila->inicio;

    while (true) {

        printf("  NO:%p => | INFO: %d | ELO ANT:%p | ELO PROX:%p \n\n", no, no->info, no->elo_ant, no->elo_prox);
        printf("    ^                     \n");
        printf("    |---------------------------| \n");

        //fila->inicio = no->elo_prox;
        no = no->elo_prox;

        if (fila->inicio == no->elo_prox) {
            printf("  NO:%p => | INFO: %d | ELO ANT:%p | ELO PROX:%p \n\n", no, no->info, no->elo_ant, no->elo_prox);
            break;
        }

    }
    printf("\n");
}


/* FIM DO MEU CODIGO */



int main() {

    // Fila Dupla Circular

    Fila* f1;

    f1 = cria();

    printf("Adiciona 1 \n");
    adiciona_fim_fila(f1, 1);

    printf("Adiciona 2 \n");
    adiciona_fim_fila(f1, 2);

    printf("Adiciona 3 \n");
    adiciona_fim_fila(f1, 3);
    imprime_fila(f1);

    printf("Adiciona 4 \n");
    adiciona_fim_fila(f1, 4);
    imprime_fila(f1);

    printf("Adiciona 5 \n");
    adiciona_inicio_fila(f1, 5);
    imprime_fila(f1);


    printf("Adiciona 6 \n");
    adiciona_inicio_fila(f1, 6);
    imprime_fila(f1);

    printf("Retira Inicio \n");
    retira_inicio(f1);
    imprime_fila(f1);

    printf("Retira Fim \n");
    retira_fim(f1);
    imprime_fila(f1);


}

