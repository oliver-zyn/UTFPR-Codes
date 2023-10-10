#include <stdio.h>
#include <stdlib.h>

// Declaração:

#define MAXTAM 100
typedef struct item Item;
typedef struct fila Fila;

// Definição: 

struct item {
    int chave;
};

struct fila {
    Item item[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Fila * criarLista() {
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

int filaCheia(Fila *f) {
    return f->tamanho == MAXTAM;
};

void enfileira(Fila *f, int chave) {
    if(filaCheia(f)) {
        printf("Fila cheia!");
    } else {
        Item novoitem;
        novoitem.chave = chave;
        f->item[f->ultimo] = novoitem;
        f->ultimo = (f->ultimo + 1) % MAXTAM;
        f->tamanho++;
    }
};

void imprimeFila(Fila *f) {
    int t, i;
    i = f->primeiro;
    for (t = 0; t < f->tamanho; t++) {
        printf("Chave: %d\n", f->item[i].chave);
        i = (i+1) % MAXTAM;
    }
};

int filaVazia(Fila *f) {
    return f->tamanho == 0;
};

void desinfileira(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: Fila Vazia!");
    } else {
        f->primeiro = (f->primeiro + 1) % MAXTAM;
        f->tamanho--;
    }
};

void liberaFila(Fila *f) {
    free(f);
};

// Teste:

int main(void) {

    Fila *f = criarLista();
    enfileira(f,1);
    enfileira(f,2);
    enfileira(f,3);
    enfileira(f,4);
    imprimeFila(f);

    desinfileira(f);
    imprimeFila(f);

    enfileira(f,5);
    enfileira(f,6);
    enfileira(f,7);
    enfileira(f,8);
    imprimeFila(f);
    liberaFila(f);
}