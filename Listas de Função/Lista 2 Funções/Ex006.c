#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void dima(int num) {
    
    if (num % 2 == 0) {
        printf("Numero par, opcao invalida!");
    } else {
        
        int i, y, j;
        
        for (i = 1; i<=(num/2) + 1; i++) {
            for (y = num; i <= y; y--) {
                printf(" ");
            }
            for (y = 1; y <= i; y++) {
                printf("*");
            }
            for (y = 2; y <= i; y++) {
                printf("*");
            }
        printf("\n");
        }
        for (i = (num/2), j = 1; i>=j; i--) {
            for (y = num; i <= y; y--) {
                printf(" ");
            }
            for (y = 1; y <= i; y++) {
                printf("*");
            }
            for (y = 2; y <= i; y++) {
                printf("*");
            }
        printf("\n");
        }
    }
}

int main(void) {
    
    int num;
    char continuar[] = "";

    do {
        
        printf("Informe um numero impar: ");
        scanf("%i", &num);
        dima(num);
    
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);

}



