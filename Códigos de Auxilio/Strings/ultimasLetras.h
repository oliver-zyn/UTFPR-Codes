int tamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

void ultimasLetras(char vetor[], char string[]) {
  int i = 0, size = 0, j = 0;

  size = tamanhoString(string);

  for(i = 0; i <= size; i++) {
    if ((string[i] != ' ' && string[i+1] == ' ') || (string[i] != ' ' && string[i + 1] == '\0')) {
      vetor[j] = string[i];
      j++;
    }
  }

  for (i = 0; i < j; i++) {
    printf("%c\t", vetor[i]);
  }

  printf("\n");
}