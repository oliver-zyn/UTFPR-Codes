#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int i, j, num, count;
    char continuar[] = "";
    
    do {
        
        printf("Quantos numeros pares divisiveis por 3 quer mostrar? ");
        scanf("%i", &num);
        
        if (num == 0) {
            printf("O numero deve ser maior ou menor que 0!");
            break;
        }
        
        if (num < 0) {
            num = num * -1;
        }
        
        count = 0;
        
        for(i = 0; count < num; i++) {
            if (i % 2 == 0) {
                if (i % 3 == 0) {
                    printf("%i \t", i);
                    count++;
                }
            }
        }
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}