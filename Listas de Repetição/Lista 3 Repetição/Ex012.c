#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    float valorUnitario, valorCompra, valorPago, troco, centavos, countQuantidade;
    int notas100, notas50, notas20, notas10, notas5, notas2, notas1, quantidade, valorCompraInt;
    char continuar[] = "";
    
    do {
        valorCompra = 0;
    
        while (1) {
            printf("Informe a quantidade de um produto: ");
            scanf("%i", &quantidade);
            if (quantidade <= 0) break;
            printf("Informe o preço unitario do produto: ");
            scanf("%f", &valorUnitario);
            if (valorUnitario <= 0) break;
            valorCompra += quantidade * valorUnitario;
            countQuantidade += quantidade;
        }
    
        printf("Valor total da compra: R$%.2f\n", valorCompra);
        printf("Valor medio da compra: R$%.2f\n", valorCompra / countQuantidade);
        
        valorCompraInt = (int) valorCompra;
        
        printf("O valor total da compra eh %i reais e %.2f centavos \n", valorCompraInt, valorCompra - valorCompraInt);
    
        troco =  valorCompra;
        printf("Troco: R$%.2f\n", troco);
    
        notas100 = troco / 100;
        troco -= notas100 * 100;
        notas50 = troco / 50;
        troco -= notas50 * 50;
        notas20 = troco / 20;
        troco -= notas20 * 20;
        notas10 = troco / 10;
        troco -= notas10 * 10;
        notas5 = troco / 5;
        troco -= notas5 * 5;
        notas2 = troco / 2;
        troco -= notas2 * 2;
        notas1 = troco / 1;
        troco -= notas1 * 1;
    
        printf("Notas de 100: %d\n", notas100);
        printf("Notas de 50: %d\n", notas50);
        printf("Notas de 20: %d\n", notas20);
        printf("Notas de 10: %d\n", notas10);
        printf("Notas de 5: %d\n", notas5);
        printf("Notas de 2: %d\n", notas2);
        printf("Notas de 1: %d\n", notas1);
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}