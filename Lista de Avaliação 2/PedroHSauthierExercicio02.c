#include <stdio.h>
#include <time.h>

void geraVetorRamdom(int vetor[], int tamanho, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
}

void mostraVetor(int vetor[], int tamanho) {
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

void geraMatriz(int SizeL, int SizeC, int matriz[SizeL][SizeC], int min, int max) {
    srand(time(NULL));
    for (int j = 0; j < SizeL; j++) {
        for (int i = 0; i < SizeC; i++) {
            matriz[j][i] = rand() % (max - min + 1) + min;
        }
    }
}

void mostraMatriz(int SizeL, int SizeC, int matriz[SizeL][SizeC]) {
    for (int j = 0; j < SizeL; j++) {
        for (int i = 0; i < SizeC; i++) {
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

int copiarElementosSemRepetir(int vetor1[], int vetor2[], int tamanhoVetor1, int SizeL, int SizeC, int matriz[SizeL][SizeC]) {
    int indiceVetor2 = 0;
    for (int j = 0; j < SizeL; j++) {
        for (int i = 0; i < SizeC; i++) {
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

void copiarElementosVetorStr(int vetor[], char string[], int tamanhoVetor) {
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

int copiaVogal(char string1[], char string2[]) {
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

int copiaConsoante(char string1[], char string3[]) {
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

int main(void) {
    
    int vetor1[10], vetor2[10], matriz[4][3], tamanhoVetor2, tamanhoString2, tamanhoString3;
    char string1[20], string2[20], string3[20]; 
    geraVetorRamdom(vetor1, 10, 97, 122);
    geraMatriz(4, 3, matriz, 97, 122);
    ordenarVetorInteiros(vetor1, 10);
    printf("==== VETOR ORDENADO ====\n");
    mostraVetor(vetor1, 10);
    printf("\n\n==== MATRIZ ====\n");
    mostraMatriz(4, 3, matriz);
    tamanhoVetor2 = copiarElementosSemRepetir(vetor1, vetor2, 10, 4, 3, matriz);
    printf("\n==== ELEMENTOS DO VETOR 1 QUE ESTAO CONTIDOS NA MATRIZ ====\n");
    ordenarVetorInteiros(vetor2, tamanhoVetor2);
    mostraVetor(vetor2, tamanhoVetor2);
    copiarElementosVetorStr(vetor2, string1, tamanhoVetor2);
    printf("\n\n==== STRING 1 ====\n");
    printf("%s", string1);
    tamanhoString2 = copiaVogal(string1, string2);
    tamanhoString3 = copiaConsoante(string1, string3);
    printf("\n\n==== STRING 2 ====\n");
    if (tamanhoString2 == 0) {
        printf("Nenhuma vogal encontrada!");
    } else {
        printf("%s", string2);
    }
    printf("\n\n==== STRING 3 ====\n");
        if (tamanhoString3 == 0) {
        printf("Nenhuma consoante encontrada!\n");
    } else {
        printf("%s\n", string3);
    }
}