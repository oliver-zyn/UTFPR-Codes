void gerarVetorCharMinuscula(char vetor[], int tam) {
    
    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 26 + 97;
    }
}