int tamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

int verificaVogal(char letra) {
  int result = 0;
  
  if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
      result++;
  }

  if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
      result++;
  }

  return result;
}

void gaguejarString(char string[], char stringGaguejada[]) {

  int tamanho, i = 0, j = 0, count = 1;
  
  tamanho = tamanhoString(string);

  for(i = 0; i <= tamanho; i++) {
    if (verificaVogal(string[i]) != 0) {
      stringGaguejada[j] = string[i];
      for (int k = 1; k <= count; k++) {
        stringGaguejada[j + k] = string[i];
      }
      j += (count + 1);
      count++;
    } else {
      stringGaguejada[j] = string[i];
      j++;
    }
  }

  stringGaguejada[j] = '\0';

  printf("%s", stringGaguejada);
}