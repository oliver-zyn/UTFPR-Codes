#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void semRepeticao(int vetor[], int result[], int tamanho) {
  
  int j = 0;
  for(int i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            result[j] = vetor[i];
            j++;
        }
    }
}

void contagemDeNumeros(int vetor[], int result[], int size) {
  
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
  semRepeticao(vetor, resultado, size);
  printf("\n==== MATRIZ ====\n");
  for (int i = 0; i < j; i++) {
    printf("%d\t%d\n", resultado[i], result[i]+1);
  }  
}

void mostraVetorInteiros(int vet[], int tamanho)
{
    int i;
    for(i=0; i<tamanho; i++)
    {
        printf("%d\t", vet[i]);
    }
    printf("\n");
}

void ordenaVetor(int vetor[], int tam) {
  int aux, i, j;
  for (j = tam - 1; j > 0; j--) {
    for (i = 0; i < j; i++) {
      if (vetor[i] > vetor[i + 1]) {
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
      }
    }
  }
}

int contadorDeEspacos(char Vetor[], int vetorespacos[]) {
    
    int size = 0;
    while(Vetor[size] != '\0') {
        size++;
    }

    int vetorEspacos[size], i, j = 0,count = 0;

    for (i = 0; i < size; i++) {
        if (Vetor[i] == ' ' && Vetor[i+1] == ' ') {
            count++;
        } else if (Vetor[i] == ' ' && Vetor[i+1] != ' ') {
            count++;
            vetorEspacos[j] = count;
            j++;
            count = 0;
        }
    }
    printf("==== VETOR ESPACOS ====\n");
    for (i = 0; i < j; i++) {
        printf("%d\t", vetorEspacos[i]);
        vetorespacos[i] = vetorEspacos[i];
    }
    return j;
    printf("\n");
}

int contadorDePalavras(char Vetor[], int vetorpalavras[]) {
    
    int size = 0;
    while(Vetor[size] != '\0') {
        size++;
    }

    int vetorPalavras[size], i, j = 0,count = 0;

    for (i = 0; i < size; i++) {
        if (Vetor[i] != ' ') {
            count++;
            if (Vetor[i + 1] == ' ' || Vetor[i + 1] == '\0') {
                vetorPalavras[j] = count;
                j++;
                count = 0;
            }
        }
    }

    printf("==== VETOR PALAVRAS ====\n");
    for (i = 0; i < j; i++) {
        printf("%d\t", vetorPalavras[i]);
        vetorpalavras[i] = vetorPalavras[i];
    }
    return j;
    printf("\n");
}

int qtdDivisores(int num) {
    
    int i, cont = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            cont++;
        }
    }
    return cont;
}

int primo(int num) {
    
    int i = 2, cont = 0, result;
    
    for (i; i<=num / 2; i++) {
        if (num%i == 0) {
            cont++;
            break;
        }
        if (cont > 1) {
            cont++;
        }
    }
    return cont;
}

void divisoresDeUmArraySemrepetidos(int vetor[], int tamanho)
{
    int i, qtde = 0;
    printf("\nVALOR\tQTDE DIVIDORES PRIMO\n");
    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            qtde = qtdDivisores(vetor[i]);
            if (primo(vetor[i]) == 0 && vetor[i] != 1) {
              printf("%d\t%d\t\tSIM\n",vetor[i], qtde);
            } else if (primo(vetor[i]) == 1 || vetor[i] == 1) {
              printf("%d\t%d\t\tNAO\n",vetor[i], qtde);
            }
        }
    }
}

int main(void) {
    
    char continuar;

    do {
        
        char texto[100];
        int vetorespacos[100], size = 0;

        printf("informe um texto: ");
        gets(texto);
        printf("\n");

        size = contadorDePalavras(texto, vetorespacos);
        printf("\n\nA string tem: %d palavras.\n", size);
        ordenaVetor(vetorespacos,size);
        printf("\n==== VETOR ORDENADO ====\n");
        mostraVetorInteiros(vetorespacos,size);
        divisoresDeUmArraySemrepetidos(vetorespacos, size);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);
        fflush(stdin);
        
    } while (continuar == 'S' || continuar == 's');
    
}



