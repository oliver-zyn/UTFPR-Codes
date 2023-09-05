#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho = 50;

    int *vetor = calloc(tamanho, sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = 2562510;
        printf("Endereco: %p, Elemento: %d, Valor: %d\n", &vetor[i], i, vetor[i]);
    }

    free(vetor);

    return 0;
}