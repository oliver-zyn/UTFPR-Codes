void semRepeticao(int vetor[], int result[], int tamanho) {
  
  int j = 0;
  for(int i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            result[j] = vetor[i];
            j++;
        }
    }
}