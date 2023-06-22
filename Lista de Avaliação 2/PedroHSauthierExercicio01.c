
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int achasizedeStringes(char string[]) {
  int tamanho = 0;
  while (string[tamanho] != '\0') {
    tamanho++;
  }
  return (tamanho - 1);
}

void mostraVetorInt(int vetorint[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%d ", vetorint[i]);
    }
}

int ehprimoOuN(int numero) {
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

void ordenarVetoresInteiros(int vetorint[], int tam) {

    int auxiliar, i, j;

    for (j = tam - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (vetorint[i] > vetorint[i + 1]) {
                auxiliar = vetorint[i];
                vetorint[i] = vetorint[i + 1];
                vetorint[i + 1] = auxiliar;
            }
        }
    }
}

void getprimos(char vetor[], char vetorPrimo[]) {

    int size = 0;
    size = achasizedeStringes(vetor);

    int j = 0;
    printf("String de caracteres primos: ");
    for(int i = 0; i < size; i++) {
        if(ehprimoOuN(vetor[i]) == 0 && vetor[i] != ' ') {
            vetorPrimo[j] = vetor[i];
            printf("%c", vetor[i]);
            fflush(stdin);
            j++;
        }
    }
        
}

int charehInt(char texto[], int textoInt[]) {

    int i, size = 0, size1 = 0, charct, j = 0, sizeEspaco = 0;
    while (texto[size] != '\0') {
        if (texto[size] != ' ') {
            size++;
        } else {
            size++;
            sizeEspaco++;
        }
    }
    
    for(i = 0; i < size; i++) {
        if (texto[i] != ' ') {
            charct = texto[i];
            textoInt[j] = charct;
            j++;
        }
    }
    size1 = size - sizeEspaco;
    return size1;
}

void vetorSemnumerosemRepeticao(int vetorint[], int resultado[], int size) {
  
  int j = 0;
  for(int i=0; i<size; i++) {
        if (i == 0 || vetorint[i] != vetorint[i-1]) {
            resultado[j] = vetorint[i];
            j++;
        }
    }
}

void contarNumerosemVetorBidimensional(int vetor[], int result[], int size) {
  
    int j = 0, count = 0;
    for(int i = 0; i < size; i++) {
        if (vetor[i] == vetor[i+1]) {
            count++;
        } else {
            result[j] = count;
            count = 0;
            j++;
        }
        }
    int resultado[size];
    vetorSemnumerosemRepeticao(vetor, resultado, size);
    for (int i = 0; i < j; i++) {
        printf("%d\t%d\n", resultado[i], result[i]+1);
    }  
}

int main(void) {
    
    char texto[50], textoPrimo[50];
    int vetorPint[50], size = 0, vetorResult[50];

    printf("Informe uma string: ");
    gets(texto);
    getprimos(texto, textoPrimo);
    size = charehInt(textoPrimo, vetorPint);
    printf("\n\n==== VETOR DE PRIMOS ====\n");
    mostraVetorInt(vetorPint, size);
    printf("\n\n==== VETOR ORDENADO ====\n");
    ordenarVetoresInteiros(vetorPint, size);
    mostraVetorInt(vetorPint, size);
    printf("\n\n==== MATRIZ ====\n");
    contarNumerosemVetorBidimensional(vetorPint, vetorResult, size);
}



