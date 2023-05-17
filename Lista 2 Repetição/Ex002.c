#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int num, i, count;
    
    printf("Informe um numero: ");
    scanf("%i", &num);
    
    for (i = 0, count = 0; count < num; i += 2, count++) {
        
        if (count % 5 == 0 && i != 0) {
            printf("\n%i\t", i);
        } else {
            printf("%i\t", i);
        }
        
    }
    return 0;
}