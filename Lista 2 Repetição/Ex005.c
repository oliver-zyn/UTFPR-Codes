#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int quantidade;
    float valorUnitario, valorCompra, valorPago, troco;
    int notas10, notas5, notas1;
    float centavos;

    valorCompra = 0;

    printf("Digite a quantidade e o valor unitario de cada produto (digite 0 para encerrar)\n");

    while (1) {
        printf("Informe a quantidade de um produto: ");
        scanf("%i", &quantidade);
        if (quantidade <= 0) break;
        printf("Informe o preço unitario do produto: ");
        scanf("%f", &valorUnitario);
        if (valorUnitario <= 0) break;
        valorCompra += quantidade * valorUnitario;
    }

    printf("Valor total da compra: R$%.2f\n", valorCompra);

    printf("Digite o valor pago pelo cliente: ");
    scanf("%f", &valorPago);

    if (valorPago < valorCompra) {
        printf("Valor pago insuficiente.\n");
        exit(1);
    }

    troco = valorPago - valorCompra;
    printf("Troco: R$%.2f\n", troco);

    notas10 = troco / 10;
    troco -= notas10 * 10;
    notas5 = troco / 5;
    troco -= notas5 * 5;
    notas1 = troco / 1;
    troco -= notas1 * 1;
    centavos = troco;

    printf("Notas de 10: %d\n", notas10);
    printf("Notas de 5: %d\n", notas5);
    printf("Notas de 1: %d\n", notas1);
    printf("Centavos: %.2f\n", centavos);

    return 0;
}