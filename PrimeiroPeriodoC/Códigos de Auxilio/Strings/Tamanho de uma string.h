int tamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}