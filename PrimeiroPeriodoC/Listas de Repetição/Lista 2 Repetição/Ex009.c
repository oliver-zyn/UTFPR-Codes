#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, num, dig, resto, soma, divisor, numlen;
    char texto[20] = "";
    
    do {
        printf("Informe um numero: ");
        scanf("%i", &num);
        soma = 0;
        
        if (num < 0) {
            break;
        }
    
        sprintf(texto, "%d", num);
        numlen = strlen(texto);
    
        for (i = 1, resto = 10, divisor = 1; i <= numlen; i++) {
        
            dig = num % resto / divisor; 
            soma += dig;
            divisor = divisor * 10;
            resto = resto * 10;
        }
        printf("Soma dos digitos: %i\n", soma);
    } while (num > 0);
    
    return 0;
}
