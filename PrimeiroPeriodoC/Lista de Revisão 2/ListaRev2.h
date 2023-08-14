#include <stdio.h>

int transformaCharEmInt(char texto[], int textoInt[]) {

    int i, size = 0, size1 = 0, charc, j = 0, sizeEspaco = 0;

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
    size1 = size - sizeEspaco;
    printf("size: %d, size1: %d, sizeEspaco: %d", size, size1, sizeEspaco);
    return size1;
}

void mostraVetorInteiro(int vetor[], int size) {

    int i;
    
    for (i = 0; i < size; i++) {
        printf("%d ", vetor[i]);
    }
}

void ordenaVetor(int vetor[], int tam) {
  int aux, i, j;
  for (j = tam - 1; j > 0; j--) {
    for (i = 0; i < j; i++) {
      if (vetor[i] > vetor[i + 1]) {
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
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

    int size2 = 0, count = 0, j = 0, y = 0;
    int vetorPar[size], vetorImpar[size];
    
    for(int i = 0; i < size; i++) {
        if (vetor[i] == vetor[i+1]) {
            count++;
        } else {
            if (vetor[i] % 2 == 0) {
                vetorPar[j] = count;
                j++;
            } else {
                vetorImpar[y] = count;
                y++;
            }
            count = 0;
        }
    }
    size2 = noReps(vetor, size);
    printf("\n\n==== MATRIZ PAR ====\n");
    for (int i = 0, j = 0; i < size2; i++) {
        if (vetor[i] % 2 == 0) {
            printf("%d\t%d\n", vetor[i], vetorPar[j]+1);
            j++;
        }
    }
    printf("\n==== MATRIZ IMPAR ====\n");
    for (int i = 0, y = 0; i < size2; i++) {
        if (vetor[i] % 2 != 0) {
            printf("%d\t%d\n", vetor[i], vetorImpar[y]+1);
            y++;
        }
    }
}

