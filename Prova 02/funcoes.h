//VETORES

void gerarVetorInteirosRandom(int vetor[], int tamanho, int min, int max) {
    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
}

void imprimeVetorInteiros(int vetor[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        if (vetor[i] != '\0') {
            printf("%d  ", vetor[i]);
        }
    }
}

void ordenarVetorInteiros(int vetor[], int tamanho) {
    int num, i, j;

    for (j = tamanho - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (vetor[i] > vetor[i + 1]) {
              num = vetor[i];
              vetor[i] = vetor[i + 1];
              vetor[i + 1] = num;
            }
        }
    }
}

//MATRIZES

void gerarMatrizInteirosRandom(int qtdLinhas, int qtdColunas, int matriz[qtdLinhas][qtdColunas], int min, int max) {
    srand(time(NULL));

    for (int j = 0; j < qtdLinhas; j++) {
        for (int i = 0; i < qtdColunas; i++) {
            matriz[j][i] = rand() % (max - min + 1) + min;
        }
    }
}

void imprimeMatrizInteiros(int qtdLinhas, int qtdColunas, int matriz[qtdLinhas][qtdColunas]) {
    for (int j = 0; j < qtdLinhas; j++) {
        for (int i = 0; i < qtdColunas; i++) {
            printf("%d  ", matriz[j][i]);
        }
        printf("\n");
    }
}

int verificaSeNumeroExisteVetorInteiro(int num, int vetor[], int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        if (num == vetor[i]) {
            return 1;
        }
    }

    return 0;
}

int copiarElementosMatrizParaVetorSemRepetir(int vetor1[], int vetor2[], int tamanhoVetor1, int qtdLinhas, int qtdColunas, int matriz[qtdLinhas][qtdColunas]) {

    int indiceVetor2 = 0;

    for (int j = 0; j < qtdLinhas; j++) {
        for (int i = 0; i < qtdColunas; i++) {
            for(int k = 0; k < tamanhoVetor1; k++) {
                if (matriz[j][i] == vetor1[k]) {
                    if (verificaSeNumeroExisteVetorInteiro(vetor1[k], vetor2, 10) != 1 || indiceVetor2 == 0) {
                        vetor2[indiceVetor2] = vetor1[k];
                        indiceVetor2++;
                    }
                }
            }
        }
    }

    return indiceVetor2;
}

//STRINGS

void copiarElementosVetorParaString(int vetor[], char string[], int tamanhoVetor) {
    int i;

    for (i = 0; i < tamanhoVetor; i++) {
        string[i] = vetor[i];
    }

    string[i] = '\0';
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

int verificaTamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

int copiaVogaisString(char string1[], char string2[]) {
    int i, tamanho = 0, indiceString2 = 0;

    tamanho = verificaTamanhoString(string1);

    for (i = 0; i <= tamanho; i++) {
        if (verificaVogal(string1[i]) != 0) {
            string2[indiceString2] = string1[i];
            indiceString2++;
        }
    }

    string2[indiceString2] = '\0';

    printf("\n\nQuantidade de vogais na string: %d", indiceString2);

    return indiceString2;
}

int copiaConsoantesString(char string1[], char string3[]) {
    int i, tamanho = 0, indiceString2 = 0;

    tamanho = verificaTamanhoString(string1);

    for (i = 0; i <= tamanho; i++) {
        if (verificaVogal(string1[i]) == 0) {
            string3[indiceString2] = string1[i];
            indiceString2++;
        }
    }

    string3[indiceString2] = '\0';

    printf("\nQuantidade de consoantes na string: %d", indiceString2);

    return indiceString2;
}