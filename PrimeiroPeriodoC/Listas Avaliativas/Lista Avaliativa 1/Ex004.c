#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n1, n2;
    
    printf("Informe o numero: ");
    scanf("%i", &n1);
    
    n2 = (n1*3 + 1) + (n1 * 2 - 1);
    
    printf("%i é a soma do sucessor do triplo + antecessor do duplo. \n", n2);
    
    return 0;
}