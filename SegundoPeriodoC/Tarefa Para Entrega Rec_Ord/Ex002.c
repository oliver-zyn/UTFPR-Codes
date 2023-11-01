#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct chamado Chamado;

struct chamado {
    int chave;
    char solicitante[30];
    char descricao[200];
};

int buscaRecursiva(Chamado vet[], char chave[], int ini, int fim) {
    if (ini >= fim) {
        return 0;
    } else if (strcmp(chave, vet[ini].solicitante) == 0) {
        return 1;
    } else {
        return buscaRecursiva(vet, chave, ini + 1, fim);
    }
}

int main() {
    int n = 2;
    Chamado vet[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nInforme o solicitante do chamado %d: ", i + 1);
        vet[i].chave = i;
        scanf(" %29[^\n]", vet[i].solicitante);
        setbuf(stdin, NULL);
        printf("\nDescricao do chamado: ");
        scanf(" %199[^\n]", vet[i].descricao);
        setbuf(stdin, NULL);
    }
    
    printf("\n======Iniciando a pesquisa por solicitante de chamado ======");
    printf("\n\nLocalizou Pedro em vet? %d", buscaRecursiva(vet, "Pedro", 0, n));
    printf("\nLocalizou Oliver em vet? %d\n", buscaRecursiva(vet, "Oliver", 0, n));
    
    return 0;
}
