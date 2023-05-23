#include <stdio.h>

void vazado(int num, char opcao) {
    
    int i, y, j;
    
    if (opcao == 'P' || opcao == 'p') {
        for (i = 1; i<=num + 1; i++) {
            for (y = 1; y < i; y++) {
                printf("*");
            }
        printf("\n");
        }
    } else if (opcao == 'V' || opcao == 'v'){
        for (i = 0; i < num; i++) {
            if (i == num - 1) {
                for (y = 0; y <= i; y++) {
                    printf("*");
                }
            } else {
                for (y = 0; y <= i; y++) {
                    if (y == 0 || y == i) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
        printf("\n");
        }
    }

}

int main()
{
    int num;
    char vazadoOuPreenchido, continuar;
    
    do {
    
        printf("Informe a altura do triangulo em linhas: ");
        scanf("%d", &num);
        
        printf("Vazado (V/v) ou preenchido(P/p)?  ");
        scanf(" %c", &vazadoOuPreenchido);
        
        vazado(num, vazadoOuPreenchido);
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
    
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
