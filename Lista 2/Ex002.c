#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int totPrestacao,QtdPaga;
    float ValorPrest, Japaga, Naopaga;
    
    printf("Informe o Total de Prestacoes: R$ ");
    scanf("%i", &totPrestacao);
    printf("Quantidade de prestacoes pagas: ");
    scanf("%i", &QtdPaga);
    printf("Valor de uma prestacao: R$ ");
    scanf("%f", &ValorPrest);
    
    Japaga = QtdPaga * ValorPrest;
    printf("Valor ja pago: R$ %.2f \n", Japaga);
    Naopaga = (totPrestacao - QtdPaga) * ValorPrest;
    printf("Valor devedor: R$ %.2f", Naopaga);
    return 0;
}