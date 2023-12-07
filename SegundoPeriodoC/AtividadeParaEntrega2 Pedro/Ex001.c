#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração:

#define MAXTAM 100
typedef struct filme Filme;
typedef struct fila Fila;

// Definição: 

struct filme {
    int chave;
    char titulo[50];
    char genero[25];
    int duracao;
};

struct fila {
    Filme filme[MAXTAM];
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

void enfileira(Fila *f, int chave, char titulo[], char genero[], int duracao) {
    if(filaCheia(f)) {
        printf("Fila cheia!");
    } else {
        Filme novofilme;
        novofilme.chave = chave;
        strcpy(novofilme.titulo, titulo);
        strcpy(novofilme.genero, genero);
        novofilme.duracao = duracao;
        f->filme[f->ultimo] = novofilme;
        f->ultimo = (f->ultimo + 1) % MAXTAM;
        f->tamanho++;
    }
};

void imprimeFila(Fila *f) {
    int t, i;
    i = f->primeiro;
    printf("\nFilmes na fila: \n");
    for (t = 0; t < f->tamanho; t++) {
        printf("\nChave: %d\n", f->filme[i].chave);
        printf("Titulo: %s\n", f->filme[i].titulo);
        printf("Genero: %s\n", f->filme[i].genero);
        printf("Duracao: %d\n", f->filme[i].duracao);
        i = (i+1) % MAXTAM;
    }
    printf("\n");
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

int criaMenus() {
    int opcao = 0;
    printf("Escolha: \nInserir filme no catalogo? - 1\nExcluir um filme do catalogo? - 2\nBuscar filme especifico? - 3\nImprimir todos os elementos? - 4\nSair - 5\n");
    scanf("%d", &opcao);
    
    return opcao;
}

int buscarElemento(Fila *f, int chave, int Exibir) {
    int t, i, found = 0;
    i = f->primeiro;
    for (t = 0; t < f->tamanho; t++) {
        if (f->filme[i].chave == chave) {
            if (Exibir == 1) {
                printf("Item de chave: %d\n\n", chave);
                printf("Chave: %d\n", f->filme[i].chave);
                printf("Titulo: %s\n", f->filme[i].titulo);
                printf("Genero: %s\n", f->filme[i].genero);
                printf("Duracao: %d\n", f->filme[i].duracao);
            }
            found = 1;
        }
        i = (i+1) % MAXTAM;
    }

    if(found == 0 && Exibir == 1) {
        printf("Nao foi encontrado.\n\n");
    }
    return found;
};

void inserirNovoFilme(Fila *f) {
    char titulo[50], genero[25];
    int chave, duracao;

    printf("Qual a chave desse filme? ");
    scanf("%d", &chave);
    fflush(stdin);

    printf("Qual o titulo desse filme? ");
    gets(titulo);
    fflush(stdin);

    printf("Qual o genero desse filme? ");
    gets(genero);
    fflush(stdin);

    printf("Qual a duracao desse filme? ");
    scanf("%d", &duracao);
    fflush(stdin);

    if (buscarElemento(f, chave, 0) == 1) {
        printf("\n Chave ja cadastrada!\n\n");
    } else {
        enfileira(f, chave, titulo, genero, duracao);
        printf("\nAdicionado com sucesso!\n\n");
    }
}

// Teste:

int main(void) {
    Fila *f = criarLista();
    int opcao = 0, chaveBus = 0;
    
    do {
        opcao = criaMenus();

        switch (opcao) {
        case 1:
            inserirNovoFilme(f);
            break;
        case 2:
            desinfileira(f);
            break;
        case 3:
            printf("Qual a chave desse filme? ");
            scanf("%d", &chaveBus);
            buscarElemento(f, chaveBus, 1);
            break;
        case 4:
            imprimeFila(f);
            break;
        case 5:
            printf("Encerrando.");
        default:
            break;
        }
    } while(opcao != 5);

    liberaFila(f);

    return 0;
}