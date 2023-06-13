void semRepeticao(int vetor[], int result[], int tamanho) {
  
  int j = 0;
  for(int i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            result[j] = vetor[i];
            j++;
        }
    }
}

void contagemDeNumeros(int vetor[], int result[], int size) {
  
  int j = 0, count = 0;

  for(int i = 0; i < size; i++) {
      if (vetor[i] == vetor[i+1]) {
        count++;
      } else {
        result[j] = count;
        count = 0;
        j++;
      }
    }
  int resultado[size];
  semRepeticao(vetor, resultado, size);
  printf("\n==== MATRIZ ====\n");
  for (int i = 0; i < j; i++) {
    printf("%d\t%d\n", resultado[i], result[i]+1);
  }  
}