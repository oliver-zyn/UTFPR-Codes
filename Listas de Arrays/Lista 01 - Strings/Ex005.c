#include <stdio.h>
#include "strings.h"

int main()
{
    char continuar;

    do {
        
        char string[100];
        
        printf("Informe um texto com ate 100 caracteres: ");
        fgets(string, sizeof(string), stdin);

        contaAlfaDecimal(string);

        printf("\nDeseja repetir o programa (S/s)");
        scanf("%c", &continuar);
        limparBuffer();

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
