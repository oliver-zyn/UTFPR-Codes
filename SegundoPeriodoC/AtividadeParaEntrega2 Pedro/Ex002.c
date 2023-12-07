#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaração:

#define MAXTAM 100
typedef struct reservas Reservas;
typedef struct lista Lista;

struct reservas {
    int id;
    char nomeHospede[80]; 
    char quarto[10];
    float custoDiaria;
};

struct lista {
    Reservas reserva[MAXTAM];
    int ultimo;
};

// Funções Básicas de Lista:

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

void adicionarItemNaListaSemRepetir(Lista *l, int chave, char nomeH[], char quarto[], float custo) {
    if(verificarListaCheia(l)) {
        printf("Erro, lista cheia!");
        return;
    }

    for(int i = 0; i <= l->ultimo; i++) {
        if(chave == l->reserva[i].id) {
            printf("Erro, chave repetida!");
            return;
        }
    }

    Reservas reservaNova;
    reservaNova.id = chave;
    strcpy(reservaNova.nomeHospede, nomeH);
    strcpy(reservaNova.quarto, quarto);
    reservaNova.custoDiaria = custo;
    l->ultimo++;
    l->reserva[l->ultimo] = reservaNova;
}   

void imprimirLista(Lista *l) {
    for(int i = 0; i <= l->ultimo; i++) {
        printf("\nChave da reserva: %d\n", l->reserva[i].id);
        printf("Nome do hospede: %s\n", l->reserva[i].nomeHospede);
        printf("Quarto: %s\n", l->reserva[i].quarto);
        printf("Custo da diaria: %.2f\n", l->reserva[i].custoDiaria);
    }
}

int retornarPosicaoItem(Lista *l, int chave) {
    int i = 0;

    while(i <= l->ultimo && l->reserva[i].id != chave) {
        i++;
    }

    if(i <= l->ultimo) {
        return i;
    } else {
        return -1;
    }
}

void removeItemDaLista(Lista *l, int chave) {
    int posicao = 0;
    posicao = retornarPosicaoItem(l, chave);

    if(posicao == -1) {
        printf("Erro, posicao inválida.");
        return;
    }

    for(int i = posicao; i < l->ultimo; i++) {
        l->reserva[i] = l->reserva[i + 1];
    }
    l->ultimo--;
}

void liberaLista(Lista *l) {
    free(l);
}

void acresce10DeTaxaDeLimpeza(Lista *lVazia, Lista *lCheia) {
    if (!verificarListaVazia(lCheia)) {
        for(int i = 0; i <= lCheia->ultimo; i++) {
            lVazia->ultimo++;
            lCheia->reserva[i].custoDiaria = lCheia->reserva[i].custoDiaria * 1.1;
            lVazia->reserva[i] = lCheia->reserva[i];
        }
    }
}

// Código de teste:

int main(void) {
    Lista *l = criarLista();
    Lista *l10 = criarLista();
    
    adicionarItemNaListaSemRepetir(l, 1, "Pedro", "123", 130);
    adicionarItemNaListaSemRepetir(l, 1, "Pedro13", "1223", 1340);
    adicionarItemNaListaSemRepetir(l, 2, "Pedrao", "124", 140.34);
    adicionarItemNaListaSemRepetir(l, 3, "Pedro13", "1223", 1340);

    printf("\n\nLista com 3 itens:");
    imprimirLista(l);

    removeItemDaLista(l, 2);

    printf("\n\nLista com 2 itens:");
    imprimirLista(l);

    acresce10DeTaxaDeLimpeza(l10, l);

    printf("\nLista com taxa de limpeza: \n");
    imprimirLista(l10);

    liberaLista(l);
    liberaLista(l10);

    return 0;
}