#include <time.h>
#include <stdio.h>
#include <string.h>
#include "atividadesExt.c"
#include "atividadesExt.h"

int main(void) {
    char continuar;
    int i = 0;
    Atvs *atividade = (Atvs *)malloc(50 * sizeof(Atvs));

    do {
        
        criaAtvs(&atividade[i]);

        printf("\nDeseja fazer um novo cadastro (S/N)?");
        scanf(" %c", &continuar);
        fflush(stdin);

        i++;
    } while (continuar == 'S' || continuar == 's');
    imprimirAtvs(atividade, i);

    free(atividade);

    return 0;
}
