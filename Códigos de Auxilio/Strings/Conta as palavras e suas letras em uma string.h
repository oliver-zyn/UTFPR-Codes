int contadorDePalavras(char Vetor[], int vetorpalavras[]) {
    
    int size = 0;
    while(Vetor[size] != '\0') {
        size++;
    }

    int vetorPalavras[size], i, j = 0,count = 0;

    for (i = 0; i < size; i++) {
        if (Vetor[i] != ' ') {
            count++;
            if (Vetor[i + 1] == ' ' || Vetor[i + 1] == '\0') {
                vetorPalavras[j] = count;
                j++;
                count = 0;
            }
        }
    }

    printf("==== VETOR PALAVRAS ====\n");
    for (i = 0; i < j; i++) {
        printf("%d\t", vetorPalavras[i]);
        vetorpalavras[i] = vetorPalavras[i];
    }
    return j;
    printf("\n");
}