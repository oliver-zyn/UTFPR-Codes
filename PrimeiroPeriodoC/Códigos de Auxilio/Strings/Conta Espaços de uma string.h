void contadorDeEspacos(char Vetor[]) {
    
    int size = 0;
    while(Vetor[size] != '\0') {
        size++;
    }

    int vetorEspacos[size], i, j = 0,count = 0;

    for (i = 0; i < size; i++) {
        if (Vetor[i] == ' ' && Vetor[i+1] == ' ') {
            count++;
        } else if (Vetor[i] == ' ' && Vetor[i+1] != ' ') {
            count++;
            vetorEspacos[j] = count;
            j++;
            count = 0;
        }
    }
    printf("==== VETOR ESPACOS ====\n");
    for (i = 0; i < j; i++) {
        printf("%d\t", vetorEspacos[i]);
    }
}