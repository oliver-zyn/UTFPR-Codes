#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100
typedef struct filme Filme;
typedef struct fila Fila;

struct filme {
    int cod;
    char titulo[200];
    char genero[50];
    int duracao;
};

struct fila {
    Filme item[MAXTAM];
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
        Filme novoitem;
        novoitem.cod = chave;
        strcpy(novoitem.titulo, titulo);
        strcpy(novoitem.genero, genero);
        novoitem.duracao = duracao;
        f->item[f->ultimo] = novoitem;
        f->ultimo = (f->ultimo + 1) % MAXTAM;
        f->tamanho++;
    }
};

void imprimeFila(Fila *f) {
    int t, i;
    i = f->primeiro;
    for (t = 0; t < f->tamanho; t++) {
        printf("\nCodigo de identificacao: %d\n", f->item[i].cod);
        printf("Titulo: %s\n", f->item[i].titulo);
        printf("Genero: %s\n", f->item[i].genero);
        printf("Duracao: %d\n", f->item[i].duracao);
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

int buscarElemento(Fila *f, int cod, int exibirMsg) {
    int t, i, encontrou = 0;
    i = f->primeiro;
    for (t = 0; t < f->tamanho; t++) {

        if (f->item[i].cod == cod) {

            if (exibirMsg == 1) {
                printf("ELEMENTO ENCONTRADO: \n\n");
                printf("Codigo de identificacao: %d\n", f->item[i].cod);
                printf("Titulo: %s\n", f->item[i].titulo);
                printf("Genero: %s\n", f->item[i].genero);
                printf("Duracao: %d\n", f->item[i].duracao);
            }
            
            encontrou = 1;
        }
        
        i = (i+1) % MAXTAM;
    }

    if (encontrou == 0 && exibirMsg == 1) {
        printf("\nNENHUM ELEMENTO FOI ENCONTRADO");
    }

    return encontrou;
};

void liberaFila(Fila *f) {
    free(f);
};

int criaMenu() {
    int opcao = 0;
    printf("\nEscolha uma opcao: \n1. Inserir elemento\n2. Excluir elemento\n3. Buscar elemento\n4. Imprimir elementos\n5. Sair");
    printf("\nOpcao: ");
    scanf("%d", &opcao);

    return opcao;
}

void inserirNovoElemento(Fila *f) {
    int cod = 0, duracao = 0;
    char titulo[200], genero[50];

    printf("Qual o codigo do filme? ");
    scanf("%d", &cod);
    fflush(stdin);

    printf("Qual o titulo do filme? ");
    gets(titulo);

    printf("Qual o genero do filme? ");
    gets(genero);

    printf("Qual a duracao, em minutos, do filme? ");
    scanf("%d", &duracao);

    if (buscarElemento(f, cod, 0) == 1) {
        printf("\nO CODIGO INFORMADO JA FOI CADASTRADO!\n");
    } else {
        enfileira(f, cod, titulo, genero, duracao);
        printf("\nADICIONADO COM SUCESSO!\n");
    }
}

int main(void) {
    Fila *f = criarLista();
    int opcao = 0, cod = 0;

    do {
        opcao = criaMenu();

        switch (opcao) {
        case 1:
            inserirNovoElemento(f);

            break;
        case 2:
            desinfileira(f);

            break;
        case 3:
            printf("Qual o codigo do filme que deseja buscar? ");
            scanf("%d", &cod);
            buscarElemento(f, cod, 1);

            break;
        case 4:
            imprimeFila(f);

            break;
        case 5:
            printf("Encerrando...");

            break;
        default:
            printf("Escolha uma opcao valida!");
            break;
        }
    } while (opcao != 5);
    
    liberaFila(f);

    return 0;
}