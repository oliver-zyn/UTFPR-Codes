#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int x = 25;
    int *p1 = &x;
    int **p2 = &p1;

    printf("Endereco de x: %\n", &x);
    printf("Conteudo de x: %i\n", x);

    printf("\nEndereco de p1: %ld\n", &p1);
    printf("Endereco apontado por p1: %ld\n", p1);
    printf("Valor apontado por p1: %i\n", *p1);

    printf("\nEndereco de p2: %ld\n", &p2);
    printf("Endereco apontado por p2: %ld\n", p2);
    printf("Endereco apontado por *p2: %ld\n", *p2);
    printf("Valor apontado por p2: %i\n", **p2);
}