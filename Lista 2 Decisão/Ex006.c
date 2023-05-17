#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(void)
{
    int n1, n2;
    
    printf("Informe qual sua aposta: ");
    scanf("%i", &n1);
    
    srand(time(NULL));
    n2 = rand() % 10;
    
    printf("Qual era o numero magico: %i\n",n2);
    if (n1 > n2) {
        printf("Errado, muito alto!");
    } else if (n1 < n2) {
        printf("Errado, muito baixo!");
    } else {
        printf("Correto, voce acertou!");
    }
 
    return 0;
}