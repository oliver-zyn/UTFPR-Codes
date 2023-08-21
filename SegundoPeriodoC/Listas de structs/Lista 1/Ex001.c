#include <stdio.h>

typedef struct pedido {
    char cliente[50];
    char description[75];
    float total;
} Pedido;

Pedido cadastroDePedido() {
    Pedido pedido;
    fflush(stdin);
    printf("Informe o nome do cliente: ");
    gets(pedido.cliente);
    fflush(stdin);
    printf("Informe uma descricao para o pedido: ");
    gets(pedido.description);
    fflush(stdin);
    printf("Informe o valor do pedido: ");
    scanf("%f", &pedido.total);
    return pedido;
}

void imprimePedido(int numCadastro, Pedido pedidos) {
    printf("\n============ PEDIDO %i ============\n\n", numCadastro);
    printf("Nome do cliente: %s\n", pedidos.cliente);
    printf("Descricao do pedido: %s\n", pedidos.description);
    printf("Valor total do pedido: %.2f\n", pedidos.total);
}

int main(void) {
    int numC = 2;
    Pedido pedido[numC];

    for (int i = 0; i < numC; i++) {
        pedido[i] = cadastroDePedido();
    }
    for (int i = 0; i < numC; i++) {
        imprimePedido(i+1, pedido[i]);
        if (i == numC-1) {
            printf("\n=============== ... ==============");
        }
    }
    
    return 0;
}