#include <stdio.h>

int tamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

int contaPalavras(char string[]) {

  int i = 0, size = 0, countPalavras = 0, novaPalavra = 1;

  size = tamanhoString(string);

  for(i = 0; i < size; i++) {
    if (string[i] == ' ') {
      novaPalavra = 1;
    } else if (novaPalavra == 1) {
      countPalavras++;
      novaPalavra = 0;
    } else {
      continue;
    }
  }

  return countPalavras;

}

int main(void) {
    
    char continuar;

    do {

      char string[100];
        
        printf("Informe uma string de ate 100 caracteres: ");
        fgets(string, sizeof(string), stdin);

        printf("n palavras: %d\n", contaPalavras(string));
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



