#include <stdio.h>

void calc(int num);
void calclimite(int inferior, int superior);

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

void calc(int num) {
    
    int i = 1, n3 = 0;
    
    for (i = 1; n3 < num; i++) {
        n3 = i * (i + 1) * (i + 2);
    }
    
    if (n3 == num) {
        printf("%d eh triangular ==> %d * %d * %d = %d", num, i - 1, i, i + 1, n3);
    } else {
        printf("%d nao eh triangular.", num);
    }
}

void calclimite(int inferior, int superior) {
    
    int i = 1, n3 = 0, j;
    
    for (inferior; inferior <= superior; inferior++) {
        for (i; n3 < inferior; i++) {
            n3 = i * (i + 1) * (i + 2);
        }
        if (n3 == inferior) {
            printf("%d eh triangular ==> %d * %d * %d = %d\n", inferior, i - 1, i, i + 1, n3);
        }
    }
}
