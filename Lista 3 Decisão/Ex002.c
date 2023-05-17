#include <stdio.h>

int main()
{
    int qtdNotas100, qtdNotas50, qtdNotas10, qtdNotas5, qtdNotas1;
    int saq;

    printf("Quanto voce quer sacar? ");
    scanf("%i", &saq);
    
    if (saq < 10 || saq > 600) {
        printf("Valor de saque invalido!");
    } else {
        
        if (saq >= 100) {
            qtdNotas100 = saq / 100;
            saq = saq % 100;
        }
        
        if (saq != 0 && saq >= 50) {
            qtdNotas50 = saq / 50;
            saq = saq % 50;
        }
        
        if (saq != 0 && saq >= 10) {
            qtdNotas10 = saq / 10;
            saq = saq % 10;
        }
        
        if (saq != 0 && saq >= 5) {
            qtdNotas5 = saq / 5;
            saq = saq % 5;
        }
        
        if (saq != 0 && saq >= 1) {
            qtdNotas1 = saq / 1;
            saq = saq - qtdNotas1;
        }
        
        printf("%i nota(s) de R$ 100,00 \n", qtdNotas100);
        printf("%i nota(s) de R$ 50,00 \n", qtdNotas50);
        printf("%i nota(s) de R$ 10,00 \n", qtdNotas10);
        printf("%i nota(s) de R$ 5,00 \n", qtdNotas5);
        printf("%i nota(s) de R$ 1,00 \n", qtdNotas1);
    }
    
    return 0;
}