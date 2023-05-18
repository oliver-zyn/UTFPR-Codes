#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    float valor, taxa, depreciacao, valordepreciado;
    int i, meses, count;
    char continuar[] = "";
    
    do {
        printf("Informe o percentual de rendimento mensal: ");
        scanf("%f", &taxa);
        if (taxa > 1 || taxa < 0) break;
        printf("Informe o valor da aplicacao: ");
        scanf("%f", &valor);
        if (valor < 0) break;
        printf("Informe o numero de meses: ");
        scanf("%i", &meses);
        if (meses < 0) break;
        
        printf("\nMes\tTaxa de Rendimento\tValor Aplicado\n");
        printf("============================================================\n");
        count = 1;
        
        for (i = 1; i <= meses; i++) {
            
            depreciacao = valor*(taxa);
            valordepreciado = valor + depreciacao;
            printf("%i\tR$ %.2f\t\t\tR$ %.2f\n", i, taxa, valordepreciado);
            valor = valordepreciado;
            count++;
            if (count % 12 == 0) {
                taxa = taxa + 0.25;
            }
        }
        
        printf("============================================================\n");
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    return 0;
}
