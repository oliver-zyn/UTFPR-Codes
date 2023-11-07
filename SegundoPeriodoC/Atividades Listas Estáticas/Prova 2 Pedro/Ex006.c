#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100

typedef struct item Item;
typedef struct pilha Pilha;

struct item{
    int numero;
};

struct pilha{
    Item item[MAXTAM];
    int topo;
};

Pilha *criaPilhaVazia(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int pilhaCheia(Pilha *p){
    return p->topo == MAXTAM-1;
}

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

void empilha(Pilha *p, int numero){
    if (pilhaCheia(p)){
        printf("Erro: Pilha cheia...!\n");
    }else{
        Item novoItem;
        novoItem.numero = numero;
        p->topo++;
        p->item[p->topo] = novoItem;
    }
}

void imprimePilha(Pilha *p){
    int tam = p->topo;
    int i;
    for(i = tam; i >= 0; i--){
        printf("Numero: %d\n",p->item[i].numero);
    }
}

void desempilha(Pilha *p){
    if(pilhaVazia(p)){
        printf("Erro: Pilha vaiza");
    }else{
        p->topo--;
    }
}

void liberaPilha(Pilha *p){
    free(p);
}

// da 6:

int comparacao(Pilha *p1, Pilha *p2) {
    int i;
    if(p1->topo == p2->topo) {
        for(i = 0; i <= p1->topo; i++) {
            if(p1->item[i].numero == p2->item[i].numero) {
                continue;
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}

void comparacaoTamanho(Pilha *p1, Pilha *p2) {
    if(p1->topo == p2->topo) {
        printf("Tem o mesmo tamanho.\n");
    } else {
        if(p1->topo > p2->topo) {
            printf("A primeira pilha eh maior com tamanho de %d\n", p1->topo);
        } else {
            printf("A segunda pilha eh maior com tamanho de %d\n", p2->topo);
        }
    }
}

void MaxMinMed(Pilha *p) {
    float max = p->item[0].numero, min = p->item[0].numero, med = 0, media = 0, count = 0;

    for(int i = 0; i <= p->topo; i++) {
        count++;
        med += p->item[i].numero;
        if(p->item[i].numero > max) {
            max = p->item[i].numero;
        }
        if(p->item[i].numero < min) {
            min = p->item[i].numero;
        }
    }  
    media = med / count;
    printf("Maior: %.2f\n", max);
    printf("Menor: %.2f\n", min);
    printf("Media: %.2f\n", media);
}

void copia(Pilha *p1, Pilha *p2) {
    p2->topo = p1->topo;

    for (int i = 0; i <= p1->topo; i++) {
        p2->item[i].numero = p1->item[i].numero;
    }
}


int Impar(Pilha *p) {
    int count = 0;

    for(int i = 0; i <= p->topo; i++) {
        if(p->item[i].numero % 2 != 0) {
            count++;
        }
    }
    return count;
}

int Par(Pilha *p) {
    int count = 0;

    for(int i = 0; i <= p->topo; i++) {
        if(p->item[i].numero % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    Pilha *p1 = criaPilhaVazia();
    Pilha *p2 = criaPilhaVazia();
    Pilha *p3 = criaPilhaVazia();

    // Teste das funções
    empilha(p1, 1);
    empilha(p1, 2);
    empilha(p1, 3);

    empilha(p2, 1);
    empilha(p2, 2);
    empilha(p2, 3);

    empilha(p3, 3);
    empilha(p3, 2);
    empilha(p3, 1);

    printf("Pilha 1:\n");
    imprimePilha(p1);

    printf("Pilha 2:\n");
    imprimePilha(p2);

    printf("Pilha 3:\n");
    imprimePilha(p3);

    printf("\nComparacao 1 e 2:\n");
    if (comparacao(p1, p2)) {
        printf("As pilhas sao iguais.\n");
    } else {
        printf("As pilhas sao diferentes.\n");
    }

    printf("\nComparacao 1 e 3:\n");
    if (comparacao(p1, p3)) {
        printf("As pilhas sao iguais.\n");
    } else {
        printf("As pilhas sao diferentes.\n");
    }

    printf("\nComparacao de tamanho 1 e 2:\n");
    comparacaoTamanho(p1, p2);

    printf("\nMaior, menor e media da pilha 1:\n");
    MaxMinMed(p1);

    Pilha *p4 = criaPilhaVazia();
    copia(p1, p4);
    printf("\nPilha 4 (copia de p1):\n");
    imprimePilha(p4);

    printf("\nQuantidade de numeros impares na pilha 1: %d\n", Impar(p1));
    printf("Quantidade de numeros pares na pilha 1: %d\n", Par(p1));

    liberaPilha(p1);
    liberaPilha(p2);
    liberaPilha(p3);
    liberaPilha(p4);

    return 0;
}