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