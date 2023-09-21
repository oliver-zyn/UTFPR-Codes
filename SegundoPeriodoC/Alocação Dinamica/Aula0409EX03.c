#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int **m, li, co, nLi = 4, nCo = 6;

    m = malloc(nLi * sizeof(int*));
    for (li = 0; li < nLi; li++) {
        m[li] = malloc(nCo * sizeof(int));
    }

    for (li = 0; li < nLi; li++) {
        for(co = 0; co < nCo; co++) {
            m[li][co] = rand() % 100 + 1;
        }
    }

    printf("======== Matriz[%d][%d] ========\n\n", nLi, nCo);

    for (li = 0; li < nLi; li++) {
        for(co = 0; co < nCo; co++) {
            printf("Endereco: %ld, Elemento[%d][%d]: %d\n", &m[li][co], li, co, m[li][co]);
        }
        printf("\n");
    }

    for (li = 0; li < nLi; li++) {
        free(m[li]);
    }

    free(m);

    return 0;
}