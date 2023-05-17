#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    float nota1, nota2, nota3, Media;
    
    printf("Informe a primeira nota: ");
    scanf("%f", &nota1);
    
    printf("Informe a segunda nota: ");
    scanf("%f", &nota2);
    
    printf("Informe a terceira nota: ");
    scanf("%f", &nota3);
    
    Media = (nota1 * 1 + nota2 * 2 + nota3 * 3) / (1 + 2 + 3);

    printf("Media Ponderada: %.1f", Media);
    return 0;
}