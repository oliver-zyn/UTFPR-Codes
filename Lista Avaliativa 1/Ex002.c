#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float minutos, horas, dias;
    int segundos;
    
    printf("Informe o tempo em segundos: ");
    scanf("%i", &segundos);
    
    minutos = segundos/60;
    horas = minutos/60;
    dias = horas/24;
    
    printf("%.2f minutos. \n", minutos);
    printf("%.2f horas. \n", horas);
    printf("%.2f dias.", dias);
    
    return 0;
}