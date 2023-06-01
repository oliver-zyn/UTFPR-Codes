int existeNoVetor(int vetor[], int size, int num) {
    
    int i,count = 0;
    
    for (i = 0; i < size; i++) {
        if (vetor[i] == num) {
            count++;
        }
    }
    return count;
}