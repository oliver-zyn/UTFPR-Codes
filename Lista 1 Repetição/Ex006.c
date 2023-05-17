#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int num, i;
    long long int mult;
    char texto[] = "", texto2[] = "";
    
    printf("Informe um numero do 0 a positivo infinito: ");
    scanf("%i", &num);
    
    mult = 1;
    
    printf("%i! = ", num);
    
    for (i = num; i >= 1; i--) {
        mult = mult * i;
        if (i != 1) {
            printf("%i * ", i);
        }
    }
    printf("1 = %lli", mult);
    
    return 0;
}