#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
3. Crie uma função que recebe o limite inferior e o limite superior de um intervalo e tem como
objetivo retornar um vetor com todos os inteiros pertencentes ao intervalo. 
*/

int main() {
    int limS, limI, y = 0;

    printf("Informe o limite Superior: ");
    scanf("%d", &limS);
    printf("Informe o limite Inferior: ");
    scanf("%d", &limI);

    int *vetor = calloc((limS-limI), sizeof(int));

    for (int i = limI; i <= limS; i++) {
        vetor[y] = i;
        y++;
    }

    for (int i = 0; i < y; i++) {
        printf("Endereco: %p, Elemento: %d, Valor: %d\n", &vetor[i], i, vetor[i]);
    }

    free(vetor);

    return 0;
}