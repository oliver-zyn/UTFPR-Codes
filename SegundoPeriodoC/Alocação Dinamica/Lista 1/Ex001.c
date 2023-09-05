#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tamanho = 50;

    int *vetor = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100 + 1;
        printf("Endereco: %p, Valor: %d\n", &vetor[i], vetor[i]);
    }

    free(vetor);

    return 0;
}
