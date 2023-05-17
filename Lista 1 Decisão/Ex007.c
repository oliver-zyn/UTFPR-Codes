#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    float x, x2,resul;
    
    printf("Informe x: ");
    scanf("%f", &x);
    
    if (x < 0) {
        resul = 2*x + 4;
        x2 = 2*x;
        printf("2x + 4\n");
        printf("2(%.1f) + 4\n",x);
        printf("%.1f + 4\n", x2);
        printf("%.1f", resul);
    } else if (x >= 0) {
        resul = x + 1;
        printf("x + 1\n");
        printf("%.1f + 1\n",x);
        printf("%.1f", resul);
    }
    
    return 0;
}