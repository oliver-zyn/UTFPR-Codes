#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "funcaoRev.h"

int main(void) {
    
    char continuar;

    do {
        
        char texto[100];
        int vetorespacos[100], size = 0;

        printf("informe um texto: ");
        gets(texto);
        printf("\n");

        size = contadorDePalavras(texto, vetorespacos);
        printf("\n\nA string tem: %d palavras.\n", size);
        ordenaVetor(vetorespacos,size);
        printf("\n==== VETOR ORDENADO ====\n");
        mostraVetorInteiros(vetorespacos,size);
        divisoresDeUmArraySemrepetidos(vetorespacos, size);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



