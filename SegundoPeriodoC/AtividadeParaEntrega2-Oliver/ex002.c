#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100
typedef struct reservas Reservas;
typedef struct lista Lista;

struct reservas {
 int cod;
 char hospede[50];
 char quarto[50];
 float custoDiaria;
};

struct lista {
  Reservas reservas[MAXTAM];
  int ultimo;
};

Lista * criarLista() {
  Lista *l = malloc(sizeof(Lista));
  l->ultimo = -1;
  return l;
}

int verificarListaCheia(Lista *l) {
  return l->ultimo == MAXTAM - 1;
}

int verificarListaVazia(Lista *l) {
  return l->ultimo == -1;
}

void incluirReserva(Lista *l, int cod, char hospede[], char quarto[], float custoDiaria) {
  if (verificarListaCheia(l)) {
      printf("Erro, lista cheia.");
      return;
  }
  Reservas item_novo;
  item_novo.cod = cod;
  strcpy(item_novo.hospede, hospede);
  strcpy(item_novo.quarto, quarto);
  item_novo.custoDiaria = custoDiaria;
  l->ultimo++;
  l->reservas[l->ultimo] = item_novo; 
}

int retornarPosicaoItem(Lista *l, int cod) {
    int i = 0;
    while(i <= l->ultimo && l->reservas[i].cod != cod) {
        i++;
    }
    if(i <= l->ultimo) {
        return i;
    } else {
        return -1;
    }
}

void removerReserva(Lista *l, int cod) {
  int posicao = 0;
  posicao = retornarPosicaoItem(l, cod);
  if(posicao == -1) {
      printf("Erro, posicao inválida.");
      return;
  }
  for(int i = posicao; i < l->ultimo; i++) {
      l->reservas[i] = l->reservas[i + 1];
  }
  l->ultimo--;
}

void liberaLista(Lista *l) {
    free(l);
}

void imprimirLista(Lista *l) {
  for(int i = 0; i <= l->ultimo; i++) {
      printf("\nCodigo: %d\n", l->reservas[i].cod);
      printf("Hospede: %s\n", l->reservas[i].hospede);
      printf("Quarto: %s\n", l->reservas[i].quarto);
      printf("Custo da diaria: %.2f\n", l->reservas[i].custoDiaria);
  }
}

void acresceTaxaLimpeza(Lista *lVazia, Lista *lCheia) {
    if (!verificarListaVazia(lCheia)) {
        for(int i = 0; i <= lCheia->ultimo; i++) {
            lVazia->ultimo++;
            lCheia->reservas[i].custoDiaria = lCheia->reservas[i].custoDiaria * 1.1;
            lVazia->reservas[i] = lCheia->reservas[i];
        }
    }
}

int main(void) {
    Lista *l = criarLista();
    Lista *lVazia = criarLista();

    incluirReserva(l, 1, "Oliver", "Quarto 01", 34.5);
    incluirReserva(l, 2, "Pedro", "Quarto 02", 37.2);
    incluirReserva(l, 3, "Carlo", "Quarto 03", 46.1);

    printf("\n===== Lista Completa =====\n");
    imprimirLista(l);

    removerReserva(l, 2);
    printf("\n===== Lista com reserva removida =====\n");
    imprimirLista(l);

    acresceTaxaLimpeza(lVazia, l);
    printf("\n===== Lista com taxa adicionada =====\n");
    imprimirLista(lVazia);
    
    liberaLista(l);
    liberaLista(lVazia);

    return 0;
}