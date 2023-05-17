#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0))*/

int main(void)
{
    int dia, mes, ano;
    char n1[15];
    
    printf("Informe a data em ddmmaaaa: ");
    scanf("%s", n1);
    dia = (n1[0] - '0') * 10 + (n1[1] - '0');
    mes = (n1[2] - '0') * 10 + (n1[3] - '0');
    ano = (n1[4] - '0') * 1000 + (n1[5] - '0') * 100 + (n1[6] - '0') * 10 + (n1[7] - '0');
    
    if (ano < 1) {
        printf("Data invalida");
    } else if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        printf("Data invalida");
    } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("Data invalida");
    } else if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) && dia > 29) {
            printf("Data invalida");
        } else if (!(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) && dia > 28) {
            printf("Data invalida");
        } else {
            printf("Data válida");
        }
    }
 
    return 0;
}