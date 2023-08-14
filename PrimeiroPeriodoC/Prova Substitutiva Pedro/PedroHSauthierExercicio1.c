#include <stdio.h>
#include <stdbool.h>

void removeRepetidos(int arrayOriginal[], int tamanhoOriginal, int arraySemRepeticao[], int* novoTamanho) {
    int contador = 0;

    for (int i = 0; i < tamanhoOriginal; i++) {
        bool repetido = false;

        // Verificar se o elemento já existe no array temporário
        for (int j = 0; j < contador; j++) {
            if (arrayOriginal[i] == arraySemRepeticao[j]) {
                repetido = true;
                break;
            }
        }

        // Se não for repetido, adicioná-lo ao array temporário
        if (!repetido) {
            arraySemRepeticao[contador] = arrayOriginal[i];
            contador++;
        }
    }

    // Atualizar o tamanho do novo array sem repetição
    *novoTamanho = contador;
}

int main() {
    int arrayOriginal[] = {1, 2, 3, 4, 1, 2, 5, 6, 3};
    int tamanhoOriginal = sizeof(arrayOriginal) / sizeof(arrayOriginal[0]);

    int arraySemRepeticao[tamanhoOriginal];
    int novoTamanho;

    removeRepetidos(arrayOriginal, tamanhoOriginal, arraySemRepeticao, &novoTamanho);

    printf("Array original:\n");
    for (int i = 0; i < tamanhoOriginal; i++) {
        printf("%d ", arrayOriginal[i]);
    }
    printf("\n");

    printf("Array sem números repetidos:\n");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", arraySemRepeticao[i]);
    }
    printf("\n");

    return 0;
}
 