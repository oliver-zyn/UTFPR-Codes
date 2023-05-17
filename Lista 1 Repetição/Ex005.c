#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, num;
    
    printf("Informe o numero de impares: ");
    scanf("%i", &num);
    
    if (num > 0) {
        for (i = 1; i <= (num*2); i = i + 2) {
            printf("%i\n", i);
        }
    } else {
        printf("Algo esta errado ☻");
    }
    
    return 0;
}