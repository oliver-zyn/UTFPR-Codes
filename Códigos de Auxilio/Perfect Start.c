#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(void) {
    
    char continuar;

    do {
        
        
        
        printf("\nDeseja repetir o programa (S/s)");
        fflush(stdin);
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');
    
}



