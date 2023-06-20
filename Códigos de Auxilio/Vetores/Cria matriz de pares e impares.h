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