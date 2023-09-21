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
            printf("Soma[%d][%d]: %d\n", li, co, m[li][co]);
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

int **soma_matriz(int **m, int **n, int n_linhas, int n_colunas) {
    int **soma = m;
    for(int i = 0; i < n_linhas; i++) {
        for (int y = 0; y < n_colunas; y++) {
            soma[i][y] += n[i][y];
        }
    }
    return soma;
}

int main() {
    srand(time(NULL));
    int **a, **m, **n, nLi = 4, nCo = 6;

    m = aloca_matriz(nLi, nCo);
    determina_matriz(m, nLi, nCo);
    printf("======== Matriz_M[%d][%d] ========\n\n", nLi, nCo);
    imprime_matriz(m, nLi, nCo);

    n = aloca_matriz(nLi, nCo);
    determina_matriz(n, nLi, nCo);
    printf("======== Matriz_N[%d][%d] ========\n\n", nLi, nCo);
    imprime_matriz(n, nLi, nCo);

    a = aloca_matriz(nLi, nCo);
    a = soma_matriz(m, n, nLi, nCo);

    printf("======== Matriz_Soma[%d][%d] ========\n\n", nLi, nCo);

    imprime_matriz(a, nLi, nCo);
    libera_matriz(m, nLi);
    libera_matriz(n, nLi);
    libera_matriz(a, nLi);

    return 0;
}