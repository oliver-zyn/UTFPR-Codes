#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    float X, Y;
    int x,y;
    
    printf("Informe o valor de X: ");
    scanf("%f", &X);
    
    printf("Informe o valor de Y: ");
    scanf("%f", &Y);
    
    printf("a) %f\n", ((X + Y) / Y) * (X*X));
    printf("b) %f\n", (X + Y) / (X - Y));
    printf("c) %f\n", ((X * X) + (Y * Y * Y))/2);
    printf("d) %f\n", (X * X * X) / (X*X));
    x = (int) X;
    y = (int) Y;
    printf("e1) %i\n", x % y);
    printf("e2) %i\n", x % 3);
    printf("e3) %i", y % 5);

    return 0;
}