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