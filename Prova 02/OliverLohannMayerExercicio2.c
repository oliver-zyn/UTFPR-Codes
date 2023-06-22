#include <stdio.h>
#include <time.h>
#include "funcoes.h"

int main(void) {
    
    int vetor1[10], vetor2[10], matriz[4][3], tamanhoVetor2, tamanhoString2, tamanhoString3;
    char string1[20], string2[20], string3[20];

    gerarVetorInteirosRandom(vetor1, 10, 97, 122);
    gerarMatrizInteirosRandom(4, 3, matriz, 97, 122);

    ordenarVetorInteiros(vetor1, 10);

    printf("==== VETOR ORDENADO ====\n");
    imprimeVetorInteiros(vetor1, 10);

    printf("\n\n==== MATRIZ ====\n");
    imprimeMatrizInteiros(4, 3, matriz);
    
    tamanhoVetor2 = copiarElementosMatrizParaVetorSemRepetir(vetor1, vetor2, 10, 4, 3, matriz);

    printf("\n==== ELEMENTOS DO VETOR 1 QUE ESTAO CONTIDOS NA MATRIZ ====\n");
    ordenarVetorInteiros(vetor2, tamanhoVetor2);
    imprimeVetorInteiros(vetor2, tamanhoVetor2);

    copiarElementosVetorParaString(vetor2, string1, tamanhoVetor2);

    printf("\n\n==== STRING 1 ====\n");
    printf("%s", string1);

    tamanhoString2 = copiaVogaisString(string1, string2);
    tamanhoString3 = copiaConsoantesString(string1, string3);

    printf("\n\n==== STRING 2 ====\n");
    if (tamanhoString2 == 0) {
        printf("Nenhuma vogal encontrada!");
    } else {
        printf("%s", string2);
    }

    printf("\n\n==== STRING 3 ====\n");
        if (tamanhoString3 == 0) {
        printf("Nenhuma consoante encontrada!\n");
    } else {
        printf("%s\n", string3);
    }
}