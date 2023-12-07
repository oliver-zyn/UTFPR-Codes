//QUESTAO 06

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100

typedef struct item {
  int chave;
} Item;

typedef struct pilha {
  Item item[MAXTAM];
  int topo;
} Pilha;

Pilha *criaPilhaVazia() {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = -1;
  return p;
}

int pilhaCheia(Pilha *p) {
  return p->topo == MAXTAM - 1;
}

int pilhaVazia(Pilha *p) {
  return p->topo == -1;
}

void empilha(Pilha *p, int chave) {
  if (pilhaCheia(p)) {
    printf("Erro: Pilha cheia...!\n");
  } else {
    Item novoItem;
    novoItem.chave = chave;
    p->topo++;
    p->item[p->topo] = novoItem;
  }
}

void desempilha(Pilha *p) {
  if (pilhaVazia(p)) {
    printf("Erro: Pilha vazia\n");
  } else {
    p->topo--;
  }
}

// 1 - Uma função para testar se as duas pilhas P1 e P2 são iguais
int pilhasIguais(Pilha *p1, Pilha *p2) {
  if (p1->topo != p2->topo) {
    return 0; 
  }

  for (int i = 0; i <= p1->topo; i++) {
    if (p1->item[i].chave != p2->item[i].chave) {
      return 0; 
    }
  }

  return 1;
}

// 2 - Caso não forem iguais diga qual pilha é maior
int compararTamanhos(Pilha *p1, Pilha *p2) {
  if (p1->topo > p2->topo) {
    return 1;
  } else if (p1->topo < p2->topo) {
    return 2;
  } else {
    return 0;
  }
}

// 3 - Uma função que forneça o maior, o menor e a média aritmética dos elementos de uma pilha
void calcularMaiorMenorMedia(Pilha *p, int *maior, int *menor, float *media) {
  if (pilhaVazia(p)) {
    *maior = *menor = 0;
    *media = 0.0;
    return;
  }

  *maior = *menor = p->item[0].chave;
  int soma = 0;

  for (int i = 0; i <= p->topo; i++) {
    int elemento = p->item[i].chave;
    soma += elemento;

    if (elemento > *maior) {
        *maior = elemento;
    }

    if (elemento < *menor) {
        *menor = elemento;
    }
  }

  *media = (float)soma / (p->topo + 1);
}

// 4 - Uma função para transferir elementos de P1 para P2 (cópia)
void transferirElementos(Pilha *p1, Pilha *p2) {
  while (!pilhaVazia(p1)) {
    int elemento = p1->item[p1->topo].chave;
    desempilha(p1);
    empilha(p2, elemento);
  }
}

// 5 - Uma função para retornar o número de elementos de uma pilha que possuem valor ímpar
int qtdImpares(Pilha *p) {
  int contImpares = 0;
  for (int i = 0; i <= p->topo; i++) {
    if (p->item[i].chave % 2 != 0) {
      contImpares++;
    }
  }
  return contImpares;
}

// 6 - Uma função para retornar o número de elementos da uma pilha que possuem valor par
int qtdPares(Pilha *p) {
  int contPares = 0;
  for (int i = 0; i <= p->topo; i++) {
    if (p->item[i].chave % 2 == 0) {
      contPares++;
    }
  }
  return contPares;
}

void imprimePilha(Pilha *p){
  int tam = p->topo;
  int i;
  printf("P2 apos transferencia\n");
  for(i = tam; i >= 0; i--){
    printf("%d\n",p->item[i].chave);
  }
}

int main() {
  Pilha *P1 = criaPilhaVazia();
  Pilha *P2 = criaPilhaVazia();

  int iguais, tamanho, maiorValor, menorValor, qtdNumerosImpares, qtdNumerosPares;
  float media;

  empilha(P1, 1);
  empilha(P1, 2);
  empilha(P1, 3);

  empilha(P2, 1);
  empilha(P2, 2);
  empilha(P2, 4);
  empilha(P2, 7);

  iguais = pilhasIguais(P1, P2);
  tamanho = compararTamanhos(P1, P2);

  printf("P1 e P2 sao iguais: %d\n", iguais);
  if (iguais != 1) {
    if (tamanho == 0) {
      printf("As pilhas tem o mesmo tamanho\n");
    } else {
      printf("A pilha maior eh a P%d\n", tamanho);
    }
  }

  calcularMaiorMenorMedia(P1, &maiorValor, &menorValor, &media);
  printf("Maior elemento de P1: %d\n", maiorValor);
  printf("Menor elemento de P1: %d\n", menorValor);
  printf("Media aritmetica de P1: %.2f\n", media);

  transferirElementos(P1, P2);
  imprimePilha(P2);

  qtdNumerosImpares = qtdImpares(P2);
  qtdNumerosPares = qtdPares(P2);
  printf("Numero de elementos impares em P2: %d\n", qtdNumerosImpares);
  printf("Numero de elementos pares em P2: %d\n", qtdNumerosPares);

  free(P1);
  free(P2);

  return 0;
}
