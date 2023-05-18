#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int i, y, x, num;
    
    printf("Informe um numero maior que 0: ");
    scanf("%i", &num);
    
    for (i = 0, y= 1, x= 1; i <= num; x += y, i++) {
        printf("%i\t",x);
        y = x - y;
    }
    return 0;
    
}