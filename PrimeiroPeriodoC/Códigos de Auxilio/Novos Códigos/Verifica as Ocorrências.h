int verificaAMaiorOcorrenciaNoVetor(int vetor[], int size) {
    
    int soma, count, k, x, y, i;
    
    soma = 1;
    count = 1;
    for (i = 0; i < size; i++) {
        
        if (vetor[i] == y) {
            count += 1;
        } else {
            count = 1;
        }
        if (soma < count) {
            k = vetor[i];
            soma = count;
        }
        y = vetor[i];
    }
    if (k == 0) {
        printf("\nMaior quantidade de ocorrencias: %i por que teve %i ocorrencias.", vetor[i], soma);
    } else {
        printf("\nMaior quantidade de ocorrencias: %i por que teve %i ocorrencias.", k, soma);
    }
    
}