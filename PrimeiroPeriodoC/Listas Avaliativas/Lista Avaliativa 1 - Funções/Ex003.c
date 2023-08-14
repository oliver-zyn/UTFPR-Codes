#include <stdio.h>

int quadrado(int numLinhas, int numColunas, int caractere) {
    
    int i, count;
    
    for (i = 0; i < (numColunas * numLinhas); i++) {
        if (count == numColunas - 1) {
            printf("%c\n", caractere);
            count = 0;
        } else {
            printf("%c ", caractere);
            count++;
        }
    }
    
}

int main() {
    int i, numLinhas, numColunas;
    char continuar, caractere;

    do {
        
        printf("Informe o numero de linhas: ");
        scanf("%d", &numLinhas);
        
        printf("Informe o numero de colunas: ");
        scanf("%d", &numColunas);
        
        printf("Informe um caractere: ");
        scanf(" %c", &caractere);
        
        quadrado(numLinhas, numColunas, caractere);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
    
    } while (continuar == 'S' || continuar == 's');

    return 0;
}