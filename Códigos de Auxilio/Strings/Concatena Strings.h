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