#include <stdio.h>

int tamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

void concatenaStrings(char string1[], char string2[]) {
  int size1 = 0, size2 = 0, i, j;

  size1 = tamanhoString(string1);
  size2 = tamanhoString(string2);

  for (i = size1, j = 0; i < (size1 + size2); i++, j++) {
    string1[i] = string2[j];
  }

  string1[size1 + size2] = '\0';

  printf("%s", string1);
}

int main() {
  char continuar;

    do {

        char string1[50], string2[50];

        printf("Informe a primeira string: ");
        fgets(string1, sizeof(string1), stdin);

        printf("Informe a segunda string: ");
        fgets(string2, sizeof(string2), stdin);

        concatenaStrings(string1, string2);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
