#include <stdio.h>

int transformaCharEmInt(char texto[], int textoInt[]) {

    int i, size = 0, charc, j = 0, sizeEspaco = 0;

    while (texto[size] != '\0') {
        if (texto[size] != ' ') {
            size++;
        } else {
            size++;
            sizeEspaco++;
        }
    }
    
    for(i = 0; i < size; i++) {
        if (texto[i] != ' ') {
            charc = texto[i];
            textoInt[j] = charc;
            j++;
        } 
    }
    size - sizeEspaco;
    return size;
}

void mostraVetorInteiro(int vetor[], int size) {

    int i;
    
    for (i = 0; i < size; i++) {
        printf("%d ", vetor[i]);
    }
}

void ordenaVetor(int vetor[], int size) {
    int i, y, z;

    for(y = size-1; y > 0; y--) {
        for(i = 0; i < size; i++){
            if (vetor[i] > vetor[i+1]) {
                z = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = z;
            }
        }
    }
}

int noReps(int vetors[], int size) {

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

void copy(int vetor0[], int vetor1[], int size1) {

    for(int i = 0; i < size1; i++) {
        vetor0[i] = vetor1[i];
    }
}

void vetorParImpar(int vetor[], int size) {

    int size2, vetorPar[size], vetorImpar[size], j = 0, y = 0;

    size2 = noReps(vetor, size);

    for (int i = 0; i < size2; i++) {
        if (vetor[i] % 2 == 0) {
            vetorPar[j] = vetor[i];
            j++;
        } else {
            vetorImpar[y] = vetor[i];
            y++;
        }
    }
    printf("\n\nNumero de pares (sem repeticao): %d\n",j);
    printf("\nNumero de impares (sem repeticao): %d\n",y);

    printf("\n==== Vetor de PARES ====\n");
    for (int i = 0; i < j; i++) {
        printf("%d  ", vetorPar[i]);
    }
    printf("\n==== Vetor de IMPARES ====\n");
    for (int i = 0; i < y; i++) {
        printf("%d  ", vetorImpar[i]);
    }
}

void matrizParImpar(int vetor[], int size) {

    int countPar = 0, count = 0, countImpar = 0, j = 0, y = 0;
    int vetorPar[size], vetorImpar[size];
    
    for(int i = 0; i < size; i++) {
        if (vetor[i] == vetor[i+1]) {
            count++;
        } else {
            result[j] = count;
            count = 0;
            j++;
        }
    }
    noReps(vetor, size);
    printf("\n==== MATRIZ ====\n");
    for (int i = 0; i < j; i++) {
        printf("%d\t%d\n", resultado[i], result[i]+1);
    }  
}

