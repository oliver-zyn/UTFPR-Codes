#include <stdio.h>
int main(void)
{
char ch;
printf("Digite um caractere: ");
scanf("%c", &ch);
if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
{
printf("Caractere faz parte do alfabeto\n");
}
else
{
printf("Caractere nao faz parte do alfabeto\n");
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    float n1, n2, n3, media, nrec, mediaf;
    
    printf("Nota 1: ");
    scanf("%f", &n1);
    printf("Nota 2: ");
    scanf("%f", &n2);
    printf("Nota 3: ");
    scanf("%f", &n3);
    
    media = ((n1 * 1) + (n2 * 3) + (n3 * 4))/8;
    
    printf("Media = %f\n", media);
    
    if (media >= 6 && media <= 10) {
        printf("Aprovado \n");
    } else if (media < 4) {
        printf("Reprovado \n");
    } else if (media >= 4 && media <= 5.9) {
        printf("Recuperacao \n");
        printf("Nota de recuperacao: ");
        scanf("%f", &nrec);
        mediaf = (nrec + media)/2;
        printf("Nova Media = %f \n", mediaf);
        if (mediaf < 6) {
            printf("Reprovado apos recuperacao");
        } else {
            printf("Aprovado apos recuperacao");
        }
    }
    return 0;
}