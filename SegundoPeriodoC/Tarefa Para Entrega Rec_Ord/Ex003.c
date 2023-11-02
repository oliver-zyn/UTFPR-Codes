#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Bubble Sort

void bubbleSortStrings(char *arr[], int n) {
    int i, j;
    char aux[100];

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(aux, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], aux);

                // Adicione uma impressão dos passos aqui
                printf("Passo %d: ", n - i);
                for (int k = 0; k < n; k++) {
                    printf("%s ", arr[k]);
                }
                printf("\n");
            }
        }
    }
}

void swapStrings(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int partition(char *arr[], int esq, int dir) {
    int pivo = esq;
    int i, j;
    char *ch;

    for (i = esq + 1; i <= dir; i++) {
        j = i;
        if (strcmp(arr[j], arr[pivo]) < 0) {
            ch = arr[j];
            while (j > pivo) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = ch;
            pivo++;
        }
    }

    return pivo;
}

void quickSortStrings(char *arr[], int esq, int dir) {
    if (esq < dir) {
        int pivo = partition(arr, esq, dir);

        printf("Pivo: %s\n", arr[pivo]);  // Impressão do pivo

        // Adicione uma impressão dos passos aqui
        printf("Passo: ");
        for (int k = esq; k <= dir; k++) {
            printf("%s ", arr[k]);
        }
        printf("\n");

        if (pivo - 1 >= esq) {
            quickSortStrings(arr, esq, pivo - 1);
        }
        if (pivo + 1 <= dir) {
            quickSortStrings(arr, pivo + 1, dir);
        }
    }
}

int main() {
    int n = 100, i = 0, y = 0;

    char **strings = (char **)malloc(n * sizeof(char *));
    char **strings2 = (char **)malloc(n * sizeof(char *));

    printf("INSERINDO VALORES NO VETOR 1\n");
    
    do {
        strings[i] = (char *)malloc(100 * sizeof(char));
        char input[100];
        printf("Informe a string %d: ", i + 1);
        gets(input);
        fflush(stdin);
        if (input[0] != '0') {
            strcpy(strings[i], input);
            i++;
        } else {
            break;
        }
    } while (1);

    printf("\nStrings desordenadas vetor 1:\n");
    for (int v = 0; v < i; v++) {
        printf("%s\n", strings[v]);
    }

    quickSortStrings(strings, 0, i - 1);

    printf("\nStrings ordenadas usando Quick Sort:\n");
    for (int v = 0; v < i; v++) {
        printf("%s\n", strings[v]);
    }

    printf("INSERINDO VALORES NO VETOR 2\n");

    do {
        strings2[y] = (char *)malloc(100 * sizeof(char));
        char input[100];
        printf("Informe a string %d: ", y + 1);
        gets(input);
        fflush(stdin);
        if (input[0] != '0') {
            strcpy(strings2[y], input);
            y++;
        } else {
            break;
        }
    } while (1);

    printf("\nStrings desordenadas vetor 2:\n");
    for (int v = 0; v < y; v++) {
        printf("%s\n", strings2[v]);
    }

    bubbleSortStrings(strings2, y);

    printf("\nStrings ordenadas usando Bubble Sort:\n");
    for (int v = 0; v < y; v++) {
        printf("%s\n", strings2[v]);
    }

    // FREE

    for (int v = 0; v < i; v++) {
        free(strings[v]);
    }
    free(strings);

    for (int v = 0; v < y; v++) {
        free(strings2[v]);
    }
    free(strings2);

    return 0;
}
