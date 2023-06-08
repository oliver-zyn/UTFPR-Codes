int contaPalavras(char string[]) {

  int i = 0, size = 0, countPalavras = 0, novaPalavra = 1;

  size = tamanhoString(string);

  for(i = 0; i < size; i++) {
    if (string[i] == ' ') {
      novaPalavra = 1;
    } else if (novaPalavra == 1) {
      countPalavras++;
      novaPalavra = 0;
    }
  }

  return countPalavras;

}