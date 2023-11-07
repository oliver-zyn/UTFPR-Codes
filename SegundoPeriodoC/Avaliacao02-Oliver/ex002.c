/*

Se uma fila representada por arranjos (vetores) não é considerada circular, sugere-se que
cada operação Desenfileira deve deslocar para “frente” todo elemento restante de uma fila. Um
método alternativo é adiar o deslocamento até que “ultimo” seja igual ao último índice do vetor.
Quando essa situação ocorre e faz-se uma tentativa de inserir um elemento na fila, a fila inteira
é deslocada para “frente”, de modo que o primeiro elemento da fila fique na primeira posição
do vetor, ou posição 0. Quais são as vantagens desse método sobre um deslocamento em cada
operação Desenfileira? Quais as desvantagens? Reescreva as funções Desenfileira, Enfileira e
Vazia usando esse novo método.

RESPOSTAS:

Vantagens:

1- Economia de tempo: O principal benefício desse método é que ele economiza tempo durante as operações de Desenfileira. Não há necessidade de mover todos os elementos da fila a cada vez que um elemento é retirado. O deslocamento ocorre apenas quando necessário.

2- Menos operações de movimento: Isso reduz a quantidade de trabalho realizado durante as operações de Desenfileira, melhorando o desempenho, especialmente em cenários em que a fila é frequentemente modificada.

Desvantagens:

2- Maior uso de memória: A desvantagem principal desse método é que ele pode resultar em um uso mais ineficiente da memória. Como os elementos permanecem nos índices originais em que foram enfileirados, pode haver fragmentação de memória, pois os espaços vazios entre os elementos não são reutilizados.

3- Complexidade de implementação: Implementar o método é mais complexo do que o deslocamento em cada operação de desenfileira. É necessário acompanhar o "primeiro" e o "último" índice da fila e realizar o deslocamento apenas quando necessário.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100

typedef struct item {
  int chave;
} Item;

typedef struct fila {
  Item item[MAXTAM];
  int primeiro;
  int ultimo;
  int tamanho;
} Fila;

Fila *criaFilaVazia(){
  Fila *f = malloc(sizeof(Fila));
  f->primeiro = 0;
  f->ultimo = -1; // Inicialize o último para -1
  f->tamanho = 0;
  return f;
}

int filaVazia(Fila *f){
  return f->tamanho == 0;
}

int filaCheia(Fila *f){
  return f->tamanho == MAXTAM;
}

void enfileira(Fila *f, Item elemento) {
  if (filaCheia(f)) {
    printf("Erro: Fila cheia!\n");
  } else {
    if (f->ultimo == MAXTAM - 1) {
      for (int i = f->primeiro; i <= f->ultimo; i++) {
        f->item[i - f->primeiro] = f->item[i];
      }
      f->ultimo = f->ultimo - f->primeiro;
      f->primeiro = 0;
    }
    f->item[++f->ultimo] = elemento;
    f->tamanho++;
  }   
}

Item desinfileira(Fila *f) {
  Item elemento;
  elemento.chave = -1; // Valor padrão se a fila estiver vazia

  if (!filaVazia(f)) {
    elemento = f->item[f->primeiro];
    f->primeiro++;
    f->tamanho--;
  } else {
    printf("Erro: Fila vazia!\n");
  }

  return elemento;
}

void imprimeFila(Fila *f) {
  int t, i;
  i = f->primeiro;
  for (t = 0; t < f->tamanho; t++) {
    printf("Chave: %d\n", f->item[i].chave);
    i = (i + 1) % MAXTAM;
  }
}

void liberaFila(Fila *f) {
  free(f);
}

int main() {
  Fila *f = criaFilaVazia();

  Item elemento1, elemento2, elemento3, elemento4, elemento5, elemento6, elemento7, elemento8;
  elemento1.chave = 1;
  elemento2.chave = 2;
  elemento3.chave = 3;
  elemento4.chave = 4;
  elemento5.chave = 5;
  elemento6.chave = 6;
  elemento7.chave = 7;
  elemento8.chave = 8;

  enfileira(f, elemento1);
  enfileira(f, elemento2);
  enfileira(f, elemento3);
  enfileira(f, elemento4);
  printf("\nLISTA:\n");
  imprimeFila(f);

  desinfileira(f);
  printf("\nLISTA:\n");
  imprimeFila(f);

  enfileira(f, elemento5);
  enfileira(f, elemento6);
  enfileira(f, elemento7);
  enfileira(f, elemento8);
  printf("\nLISTA:\n");
  imprimeFila(f);
  liberaFila(f);

  return 0;
}

