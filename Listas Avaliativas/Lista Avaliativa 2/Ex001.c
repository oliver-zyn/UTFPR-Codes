#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, numVer, num, dig, resto, digitoVer, count, divisor, numlen;
    char texto[20] = "";
    
    printf("Informe um digito: ");
    scanf("%i", &digitoVer);
    
    do {
        printf("Informe um numero: ");
        scanf("%i", &numVer);
        if (numVer == 0) break;
        sprintf(texto, "%d", numVer);
        numlen = strlen(texto);
        count = 0;
        for (i = 1, resto = 10, divisor = 1; i <= numlen; i++) {
            dig = numVer % resto / divisor;
            divisor = divisor * 10;
            resto = resto * 10;
            if (dig == digitoVer) {
                count += 1;
            }
        }
        printf("%i\n", count);
    } while (numVer != 0);
    
    return 0;
}