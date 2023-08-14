#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int Includes(char string[], char substring[]) {

    int resultado = 0, i = 0, j;

    while(string[i] != '\0') {
        if (string[i] == substring[0]) {
            j = 0;
            while (substring[j] != '\0' && string[i] != '\0') {
                if (string[i] != substring[j]) {
                    break;
                }
                i++;
                j++;
            }
            if (substring[j] == '\0') {
                resultado = 1;
            }
        }
        i++;
    }
    return resultado;
}

int main(void) {
    
    char continuar;
    char Texto[50], Subtexto[10];

    do {
        
        printf("Informe o texto principal: ");
        fflush(stdin);
        gets(Texto);
        printf("Informe o texto secundario: ");
        fflush(stdin);
        gets(Subtexto);
        
        if (Includes(Texto, Subtexto) == 1) {
            printf("'%s', faz parte de '%s'", Subtexto, Texto);
        } else {
            printf("'%s', nao faz parte de '%s'", Subtexto, Texto);
        }
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



