#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int i;
    
    printf("Informe a sua idade: ");
    scanf("%i", &i);
    
    if (i < 0) {
        printf("%i Anos, Opcao invalida", i);
    } else if (i >= 0 && i <= 4) {
        printf("%i Anos, AINDA EH CEDO PARA JOGAR FUTEBOL!", i);
    } else if (i >= 5 && i <= 10) {
        printf("%i Anos, Sub-10", i);
    } else if (i >= 11 && i <= 17) {
        printf("%i Anos, Sub-17", i);
    } else if (i >= 18 && i <= 20) {
        printf("%i Anos, Sub-20", i);
    } else if (i >= 21 && i <= 35) {
        printf("%i Anos, Profissional", i);
    } else if (i >= 36 && i <= 55) {
        printf("%i Anos, Master", i);
    } else if (i >= 56) {
        printf("%i Anos, MELHOR APOSENTAR AS CHUTEIRAS!", i);
    } 
    
    return 0;
}