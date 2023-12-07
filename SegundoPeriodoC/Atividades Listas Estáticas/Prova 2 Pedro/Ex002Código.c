/* 2 - Se uma fila representada por arranjos (vetores) não é considerada circular, sugere-se que
cada operação Desenfileira deve deslocar para “frente” todo elemento restante de uma fila. Um
método alternativo é adiar o deslocamento até que “ultimo” seja igual ao último índice do vetor.
Quando essa situação ocorre e faz-se uma tentativa de inserir um elemento na fila, a fila inteira
é deslocada para “frente”, de modo que o primeiro elemento da fila fique na primeira posição
do vetor, ou posição 0. Quais são as vantagens desse método sobre um deslocamento em cada
operação Desenfileira? Quais as desvantagens? Reescreva as funções Desenfileira, Enfileira e
Vazia usando esse novo método. */

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100
typedef struct item Item;
typedef struct fila Fila;

struct item{
    int chave;
};

struct fila{
    Item item[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Fila *criaFilaVazia(){
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

int filaCheia(Fila *f){
    return f->tamanho == MAXTAM;
}

int filaVazia(Fila *f){
    return f->tamanho == 0;
}

void enfileira(Fila *f, int chave){
    if (filaCheia(f)){
        printf("Erro: Fila cheia!");
    } else {
        if (f->ultimo == MAXTAM) {
            int i, j;
            for (i = 0, j = f->primeiro; j < f->ultimo; i++, j++) {
                f->item[i] = f->item[j];
            }
            f->primeiro = 0;
            f->ultimo = i;
        }
        
        Item novoitem;
        novoitem.chave = chave;
        f->item[f->ultimo] = novoitem;
        f->ultimo++;
        f->tamanho++;
    }
}

void desinfileira(Fila *f){
    if (filaVazia(f)){
        printf("Erro: Fila vazia!");
    } else {
        f->primeiro++;
        f->tamanho--;
    }
}

void imprimeFila(Fila *f){
    int t, i;
    i = f->primeiro;
    for(t = 0; t < f->tamanho; t++){
        printf("Chave: %d\n",f->item[i].chave);
        i = (i+1) % MAXTAM;
    }
}

void liberaFila(Fila *f){
    free(f);
}

// Teste:

int main(void) {

    Fila *f = criaFilaVazia();
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