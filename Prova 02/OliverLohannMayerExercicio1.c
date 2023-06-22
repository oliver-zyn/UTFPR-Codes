#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int verificaTamanhoString(char str[]) {
  int tamanho = 0;

  while (str[tamanho] != '\0') {
    tamanho++;
  }

  return (tamanho - 1);
}

void imprimeVetorInteiros(int vetor[], int tamanho) {
    int i;

    for(i = 0; i < tamanho; i++) {
        if (vetor[i] != '\0') {
            printf("%d  ", vetor[i]);
        }
    }
}

int verificaNumeroPrimo(int numero) {
    int i, cont = 0;
    for (i = 2; i<=numero / 2; i++) {
        if (numero%i == 0) {
            cont++;
            break;
        }
        if (cont > 1) {
            cont++;
        }
    }
    return cont;
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

void verificaCaracteresPrimos(char string[], char stringPrimos[]) {
    int tamanho = 0, indiceStringPrimos = 0;

    tamanho = verificaTamanhoString(string);

    for(int i = 0; i < tamanho; i++) {
        if(string[i] != ' ' && verificaNumeroPrimo(string[i]) == 0) {
            stringPrimos[indiceStringPrimos] = string[i];
            indiceStringPrimos++;
        }
    }
        
    printf("String de caracteres primos: %s", stringPrimos);
}

int converteCharParaInt(char string[], int stringPrimos[]) {
    int i, indiceStringPrimos = 0, tamanho = 0, numeroConvertido, caractereEspaco = 0;

    while (string[tamanho] != '\0') { 
        tamanho++;
    }
    
    for(i = 0; i <= tamanho; i++) {
        if (string[i] != ' ') {
            numeroConvertido = string[i];
            stringPrimos[indiceStringPrimos] = numeroConvertido;
            indiceStringPrimos++;
        } else {
          caractereEspaco++;
        }
    }

    return tamanho - caractereEspaco;
}

int removeNumerosRepetidosVetor(int vetor[], int vetorSemRepeticao[], int tamanho) {
  int indiceVetorSemRepeticao = 0;

  for(int i = 0; i < tamanho; i++) {
      if (i == 0 || vetor[i] != vetor[i - 1]) {
          vetorSemRepeticao[indiceVetorSemRepeticao] = vetor[i];
          indiceVetorSemRepeticao++;
      }
  }

  return indiceVetorSemRepeticao;
}

void imprimeMatrizInteiro(int linha, int coluna, int matriz[linha][coluna]) {
    for (int j = 0; j < linha; j++) {
        for (int i = 0; i < coluna; i++) {
            printf("%d\t", matriz[j][i]);
        }
        printf("\n");
    }
}

void imprimeMatrizFinal(int vetor[], int vetorFinal[], int tamanho) {
    int indiceVetorFinal = 0, count = 0, vetorSemRepeticao[tamanho], tamanhoVetorSemRepeticao = 0;

    for(int i = 0; i < tamanho; i++) {
        if (vetor[i] == vetor[i + 1]) {
            count++;
        } else {
            vetorFinal[indiceVetorFinal] = count;
            count = 0;
            indiceVetorFinal++;
        }
    }

    tamanhoVetorSemRepeticao = removeNumerosRepetidosVetor(vetor, vetorSemRepeticao, tamanho);

    int matriz[tamanhoVetorSemRepeticao][2];

    for (int i = 0; i < indiceVetorFinal; i++) {
      matriz[i][0] = vetorSemRepeticao[i];
      matriz[i][1] = vetorFinal[i] + 1;
    }

    imprimeMatrizInteiro(indiceVetorFinal, 2, matriz);
}

int main(void) {
    
    char string[100], stringPrimos[100];
    int vetorPrimosInt[100], tamanhoVetorPrimosInt = 0, vetorResult[100];

    printf("Informe uma string: ");
    gets(string);

    verificaCaracteresPrimos(string, stringPrimos);

    tamanhoVetorPrimosInt = converteCharParaInt(stringPrimos, vetorPrimosInt);

    printf("\n\n==== VETOR DE PRIMOS ====\n");
    imprimeVetorInteiros(vetorPrimosInt, tamanhoVetorPrimosInt);

    printf("\n\n==== VETOR ORDENADO ====\n");
    ordenarVetorInteiros(vetorPrimosInt, tamanhoVetorPrimosInt);
    imprimeVetorInteiros(vetorPrimosInt, tamanhoVetorPrimosInt);

    printf("\n\n==== MATRIZ ====\n");
    imprimeMatrizFinal(vetorPrimosInt, vetorResult, tamanhoVetorPrimosInt);
}



