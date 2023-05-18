#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    float valor, taxa, depreciacao, valordepreciado;
    int i, anos;
    
    printf("Informe o valor da taxa: ");
    scanf("%f", &taxa);
    printf("Informe o valor do bem: ");
    scanf("%f", &valor);
    printf("Informe o numero de anos: ");
    scanf("%i", &anos);
    
    printf("\nAnos\tValor do Bem\tDepreciacao\tValor Depreciado\n");
    printf("============================================================\n");
    
    for (i = 1; i <= anos; i++) {
        depreciacao = valor*(taxa/100);
        valordepreciado = valor - depreciacao;
        printf("%i\tR$ %.2f\tR$ %.2f\tR$%.2f\n", i, valor, depreciacao, valordepreciado);
        valor = valordepreciado;
    }
    
    printf("============================================================\n");
    
    return 0;
}