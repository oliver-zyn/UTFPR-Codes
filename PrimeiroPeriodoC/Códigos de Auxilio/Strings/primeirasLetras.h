int tamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

void primeirasLetras(char vetor[], char string[]) {
  int i = 0, size = 0, j = 0;

  size = tamanhoString(string);

  for (i = 0; i <= size; i++) {
    if ((i == 0 && string[i] != ' ') || (string[i] != ' ' && string[i-1] == ' ')) {
      vetor[j] = string[i];
      j++;
    }
  }
  
  for (i = 0; i < j; i++) {
    printf("%c  ", vetor[i]);
  }
  
  printf("\n");
}