#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **aloca_matriz(int n_linhas, int n_colunas) {
    int **m, li;
    m = malloc(n_linhas * sizeof(int*));
    for (li = 0; li < n_linhas; li++) {
        m[li] = malloc(n_colunas * sizeof(int));
    }
    return m;
}

void determina_matriz(int **m, int n_linhas, int n_colunas) {
    int li, co;
    for (li = 0; li < n_linhas; li++) {
        for(co = 0; co < n_colunas; co++) {
            m[li][co] = rand() % 100 + 1;
        }
    }
}

void imprime_matriz(int **m, int n_linhas, int n_colunas) {
    int li, co;
    for (li = 0; li < n_linhas; li++) {
        for(co = 0; co < n_colunas; co++) {
            printf("Endereco: %ld, Elemento[%d][%d]: %d\n", &m[li][co], li, co, m[li][co]);
        }
        printf("\n");
    }
}

void libera_matriz(int **m, int n_linhas) {
    int li;
    for (li = 0; li < n_linhas; li++) {
        free(m[li]);
    }
    free(m);
}

int main() {
    srand(time(NULL));
    int **m, nLi = 4, nCo = 6;
    m = aloca_matriz(nLi, nCo);
    determina_matriz(m, nLi, nCo);

    printf("======== Matriz[%d][%d] ========\n\n", nLi, nCo);

    imprime_matriz(m, nLi, nCo);
    libera_matriz(m, nLi);

    return 0;
}