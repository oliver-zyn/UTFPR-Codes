#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    int n1, n2;
    float n3, n4;
    
    printf("Informe o primeiro numero: ");
    scanf("%i", &n1);
    
    printf("Informe o segundo numero: ");
    scanf("%i", &n2);
    
    printf("%i + %i = %i\n",n1,n2,n1+n2);
    printf("%i - %i = %i\n",n1,n2,n1-n2);
    printf("%i * %i = %i\n",n1,n2,n1*n2);
    printf("%i / %i = %i\n",n1,n2,n1/n2);
    n3 = (float) n1;
    n4 = (float) n2;
    printf("%i / %i = %.2f\n",n1,n2,n3/n4);
    printf("%i %% %i = %i\n",n1,n2,n1%n2);
    return 0;
}