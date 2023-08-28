#include <stdio.h>

typedef struct instrumento {
    char modelo[25];
    char marca[25];
    float valor;
} Instrumento;

Instrumento cadastroDeInstrumento() {
    Instrumento inst;
    fflush(stdin);
    printf("Informe o modelo: ");
    gets(inst.modelo);
    fflush(stdin);
    printf("Informe a marca: ");
    gets(inst.marca);
    fflush(stdin);
    printf("Informe o valor: ");
    scanf("%f", &inst.valor);
    return inst;
}

void imprimeInstrumento(int verifi, int numCadastro, Instrumento inst) {
    if (inst.valor < verifi) {
        printf("\n============ INSTRUMENTO %i ============\n\n", numCadastro);
        printf("Nome do modelo: %s\n", inst.modelo);
        printf("Marca: %s\n", inst.marca);
        printf("Valor: %.2f\n", inst.valor);
    }
}

int main(void) {
    int numC = 5, p;
    Instrumento isnt[numC];

    for (int i = 0; i < numC; i++) {
        isnt[i] = cadastroDeInstrumento();
    }

    do {
        printf("\n\nInforme o valor de 'p': ");
        scanf("%d", &p);
        if (p == 0) {
            break;
        }
        for (int i = 0; i < numC; i++) {
            imprimeInstrumento(p, i+1, isnt[i]);
            if (i == numC-1) {
                printf("\n================== ... =================");
            }
        }
    } while (p != 0);

    return 0;
}