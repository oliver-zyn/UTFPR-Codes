#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    float X, A, B;
    
    printf("Informe o valor de A: ");
    scanf("%f", &A);
    
    printf("Informe o valor de B: ");
    scanf("%f", &B);
    
    printf("Antes da troca: A = %.1f, B = %.1f\n",A,B);
    X = A;
    A = B;
    B = X;
    printf("Apos a troca: A = %.1f, B = %.1f",A,B);
    return 0;
}