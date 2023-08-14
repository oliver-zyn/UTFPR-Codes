#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0))*/

int main(void)
{
    int dia, mes, ano, dia2, mes2, ano2, n3, n4;
    char n1[15], n2[15];
    
    printf("Informe a data em ddmmaaaa: ");
    scanf("%s", n1);
    dia = (n1[0] - '0') * 10 + (n1[1] - '0');
    mes = (n1[2] - '0') * 10 + (n1[3] - '0');
    ano = (n1[4] - '0') * 1000 + (n1[5] - '0') * 100 + (n1[6] - '0') * 10 + (n1[7] - '0');
    
    printf("Informe a segunda data em ddmmaaaa: ");
    scanf("%s", n2);
    dia2 = (n2[0] - '0') * 10 + (n2[1] - '0');
    mes2 = (n2[2] - '0') * 10 + (n2[3] - '0');
    ano2 = (n2[4] - '0') * 1000 + (n2[5] - '0') * 100 + (n2[6] - '0') * 10 + (n2[7] - '0');
    

    
    if (ano < 1) {
        printf("Data invalida\n");
    } else if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        printf("Data invalida\n");
    } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("Data invalida\n");
    } else if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) && dia > 29) {
            printf("Data invalida\n");
        } else if (!(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) && dia > 28) {
            printf("Data invalida\n");
        } else {
            n3 = 1;
            printf("Data válida\n");
         }
    }
    n4 = 0;
    if (ano2 < 1) {
        printf("Data invalida\n");
    } else if (mes2 < 1 || mes2 > 12 || dia2 < 1 || dia2 > 31) {
        printf("Data invalida\n");
    } else if ((mes2 == 4 || mes2 == 6 || mes2 == 9 || mes2 == 11) && dia2 > 30) {
        printf("Data invalida\n");
    } else if (mes2 == 2) {
        if ((ano2 % 4 == 0 && ano2 % 100 != 0 || ano2 % 400 == 0) && dia2 > 29) {
            printf("Data invalida\n");
        } else if (!(ano2 % 4 == 0 && ano2 % 100 != 0 || ano2 % 400 == 0) && dia2 > 28) {
            printf("Data invalida\n");
        } else {
            n4 = 1;
            printf("Data valida\n");
        }
    }
    printf("%i\n", n3);
    printf("%i\n", n4);

    if ((n3 == 1) && (n4 == 1)) {
        if (ano > ano2) {
        printf("A maior data é %.2i/%.2i/%.4i", dia, mes, ano);
    } else if (ano2 > ano) {
        printf("A maior data é %.2i/%.2i/%.4i", dia2, mes2, ano2);
    } else {
        if (mes > mes2) {
            printf("A maior data é %.2i/%.2i/%.4i", dia, mes, ano);
        } else if (mes2 > mes) {
            printf("A maior data é %.2i/%.2i/%.4i", dia2, mes2, ano2);
        } else {
            if (dia > dia2) {
                printf("A maior data é %.2i/%.2i/%.4i", dia, mes, ano);
            } else if (dia2 > dia) {
                printf("A maior data é %.2i/%.2i/%.4i", dia2, mes2, ano2);
            } else {
                printf("Datas iguais! %.2i/%.2i/%.4i", dia2, mes2, ano2);
            }
        }
    }
    } else {
        printf("Datas invalidas!");
    }
    
    return 0;

}