#include <stdio.h>

void montaArvore(int num) {
    int i, j;
    
    for(i = 0; i <= num; i++) {
        for(j = num; i <= j; j--) {
            printf(" ");
        }
        
        for(j = 0; j <= i; j++) {
            printf("*");
        }
    
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("\n");
    }
    
    for(i = 0; i <= 5; i++) {
        for(j = 0; j <= num; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    
}

int main()
{
    int num;
    char continuar;
    
    do {
    
        printf("Insira a altura (em linhas) da arvore: ");
        scanf("%d", &num);
        
        montaArvore(num);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
    
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
