#include <stdio.h>

int tamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

void copiaPrimeiraPalavra(char string[]) {
    int i, j = 0, primeiroEspaco = 0;
    char stringPalavra[50];
    
    for (i = 0; string[i] != '\0'; i++) {
        
        if (primeiroEspaco == 0) {
            while (string[i] == ' ') {
                i++;
            }
        }
        
        primeiroEspaco = 1;
        
        if (string[i] != ' ' && string[i] != '\n') {
            stringPalavra[j] = string[i];
            j++;
        } else {
            break;
        }
        
    }
    
    stringPalavra[j] = '\0';
    printf("%s\n", stringPalavra);
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
    }
  }

  return countPalavras;

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
    printf("%c\t", vetor[i]);
  }
  
  printf("\n");
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

 /* Universidade   Tecnologica  Federal    do  Parana  */

int main(void) {
    
    char continuar;

    do {

      char string[100], vetorUltimas[100], vetorPrimeiras[100];
        
        printf("Informe uma string de ate 100 caracteres: ");
        gets(string);

        printf("\n'%s' tem %d palavras\n\n", string, contaPalavras(string));
        primeirasLetras(vetorPrimeiras, string);
        ultimasLetras(vetorUltimas, string);
        printf("Primeira palavra: ");
        copiaPrimeiraPalavra(string);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



