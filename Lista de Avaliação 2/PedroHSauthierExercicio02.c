#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gerarVetor(int vetor[], int size, int min, int max) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
}

void gerarMatriz(int SizeL, int SizeC, int min, int max, int vetor[SizeL][SizeC]) {
    
    srand(time(NULL));

    for (int i = 0; i < SizeL; i++) {
        for (int j = 0; j < SizeC; j++) {
            vetor[i][j] = rand() % (max - min + 1) + min;
        }
        
    }
}

void ordenarVetoresInteiros(int vetorint[], int tam) {

    int auxiliar, i, j;

    for (j = tam - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (vetorint[i] > vetorint[i + 1]) {
                auxiliar = vetorint[i];
                vetorint[i] = vetorint[i + 1];
                vetorint[i + 1] = auxiliar;
            }
        }
    }
}

void mostraVetorInt(int vetorint[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++) {
        printf("%d ", vetorint[i]);
    }
}

void mostraMatriz( int SizeL, int SizeC, int matriz[SizeL][SizeC]) {
    int i, j;

    for(i=0; i<SizeL; i++) {
        for(j = 0; j < SizeC; j++) {
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
}

int noRepeticaoEmvetor(int vetors[], int size) {

    int i = 0, j = 0;
    int vetorR[50];
    for (i = 0; i < size; i++) {
        if (i == 0 || vetors[i] != vetors[i-1]) {
            vetorR[j] = vetors[i];
            j++;
        }
    }
    for(i = 0; i < size; i++) {
        if (vetorR[i] != '\0') {
            vetors[i] = vetorR[i];
        } else {
            vetors[i] = '\0';
        }
    }
    return j;
}

int elementos(int size, int sizeL, int sizeC, int vetor[size], int matriz[sizeL][sizeC], int vetor2[]) {

    int i, j, y, z = 0, size1;

    for(i = 0; i < size; i++) {
        for(y = 0; y < sizeL; y++) {
            for(j = 0; j < sizeC; j++) {
                if (vetor[i] == matriz[j][y]) {
                    vetor2[z] = vetor[i];
                }
            }
        }
    }
    ordenarVetoresInteiros(vetor2, size);
    size1 = noRepeticaoEmvetor(vetor2, size);
    return size1;
}

int main(void) {

    int vetor1[10], matriz[4][3], vetor2[10], vetorRes[10], size1;

    gerarVetor(vetor1, 10, 97, 122);
    ordenarVetoresInteiros(vetor1, 10);
    printf("==== VETOR ORDENADO ====\n");
    mostraVetorInt(vetor1, 10);
    gerarMatriz(4, 3, 97, 122, matriz);
    printf("\n\n==== MATRIZ ====\n");
    mostraMatriz(4, 3, matriz);
    printf("\n\n==== ELEMENTOS DO VETOR 1 QUE ESTAO NA MATRIZ ====\n");
    size1 = elementos(10, 4, 3, vetor1, matriz, vetor2);
    mostraVetorInt(vetor2, size1);
}



