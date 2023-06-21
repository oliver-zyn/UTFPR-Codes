#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    
    char continuar;

    do {
        
        
        
        printf("\nDeseja repetir o programa? (S/s)");
        scanf("%c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



