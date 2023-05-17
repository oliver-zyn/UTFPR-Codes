#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int mes, dia;
    
    printf("Informe o mes: ");
    scanf("%i", &mes);
    printf("Informe o dia: ");
    scanf("%i", &dia);
    
    if ((dia >= 22 && mes == 12) || (dia <= 20 && mes == 1)) {
        printf("Capricornio");
    } else if ((dia >= 21 && mes == 1) || (dia <= 19 && mes == 2)) {
        printf("Aquario");
    } else if ((dia >= 20 && mes == 2) || (dia <= 20 && mes == 3)) {
        printf("Peixes");
    } else if ((dia >= 21 && mes == 3) || (dia <= 20 && mes == 4)) {
        printf("Aries");
    } else if ((dia >= 21 && mes == 4) || (dia <= 20 && mes == 5)) {
        printf("Touro");
    } else if ((dia >= 21 && mes == 5) || (dia <= 20 && mes == 6)) {
        printf("Gemeos");
    } else if ((dia >= 21 && mes == 6) || (dia <= 21 && mes == 7)) {
        printf("Cancer");
    } else if ((dia >= 22 && mes == 7) || (dia <= 22 && mes == 8)) {
        printf("Leao");
    } else if ((dia >= 23 && mes == 8) || (dia <= 22 && mes == 9)) {
        printf("Virgem");
    } else if ((dia >= 23 && mes == 9) || (dia <= 22 && mes == 10)) {
        printf("Libra");
    } else if ((dia >= 23 && mes == 10) || (dia <= 21 && mes == 11)) {
        printf("Escorpiao");
    } else if ((dia >= 22 && mes == 11) || (dia <= 21 && mes == 12)) {
        printf("Sagitario");
    } else {
        printf("Numeros errados.");
    }
    
    return 0;
}