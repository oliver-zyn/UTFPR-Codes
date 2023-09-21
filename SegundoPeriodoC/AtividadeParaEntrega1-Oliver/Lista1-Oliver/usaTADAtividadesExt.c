#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "atividadesExt.c"
#include "atividadesExt.h"

int main(void) {
    char continuar;
    int i = 0;
    Atividade *atividades = malloc(50 * sizeof(Atividade));

    do {
        cadastrarAtividade(&atividades[i]);

        printf("\nDeseja fazer um novo cadastro (S/N)");
        scanf(" %c", &continuar);
        fflush(stdin);

        i++;
    } while (continuar == 'S' || continuar == 's');

    imprimirAtividades(atividades, i);

    free(atividades);

    return 0;
}
