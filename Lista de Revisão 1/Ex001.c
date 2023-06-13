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
        int vetorespacos[100], size = 0, vetorResult[100];

        printf("informe um texto: ");
        gets(texto);

        size = contadorDeEspacos(texto, vetorespacos);
        ordenaVetor(vetorespacos,size);
        printf("\n==== VETOR ORDENADO ====\n");
        mostraVetorInteiros(vetorespacos,size);
        contagemDeNumeros(vetorespacos, vetorResult, size);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



