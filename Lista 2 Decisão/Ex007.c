#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char c;
    
    printf("Informe o charactere: ");
    scanf("%c", &c);
    
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
        printf("%c\n", c);
        printf("O caractere %c pertence ao alfabeto.\n", c);
    } else if (c >= 'A' && c <= 'Z') {
        printf("%c\n", c);
        printf("O caractere %c pertence ao alfabeto.\n", c);
    } else {
        printf("%c\n", c);
        printf("O caractere não pertence ao alfabeto.\n");
    }

    if (c >= 'A' && c <= 'Z') {
        switch (c) {
        case 'A': 
        case 'E': 
        case 'I': 
        case 'O': 
        case 'U':
            printf("Vogal");
            break;
        default:
            printf("Consoante");
            break;
    }
    }
 
    return 0;
}