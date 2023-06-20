#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "ListaRev2.h"

int main(void) {

    char continuar;

    do {

        char texto[100];
        int vetor[100], vetor0[100], size = 0;

        printf("Informe um texto: ");
        gets(texto);
        fflush(stdin);
        size = transformaCharEmInt(texto, vetor);
        printf("\n\n==== VETOR ====\n");
        mostraVetorInteiro(vetor, size);
        ordenaVetor(vetor, size);
        copy(vetor0, vetor, size);
        printf("\n\n==== VETOR ORDENADO ====\n");
        mostraVetorInteiro(vetor, size);
        vetorParImpar(vetor, size);
        matrizParImpar(vetor0, size);

        printf("\nDeseja continuar S/s? ");
        scanf("%c", &continuar);
        fflush(stdin);

    } while (continuar == 'S' || continuar == 's');

}