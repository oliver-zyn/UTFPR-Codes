#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Bubble Sort

void bubbleSortStrings(char *arr[], int n) {
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        if (swapped == 0) {
            break;
        }
    }
}

// Quick Sort

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

        if (pivo - 1 >= esq) {
            quickSortStrings(arr, esq, pivo - 1);
        }
        if (pivo + 1 <= dir) {
            quickSortStrings(arr, pivo + 1, dir);
        }
    }
}

int main() {
    char **strings = NULL;
    int n;
    
    printf("Informe o número de strings: ");
    scanf("%d", &n);

    strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        strings[i] = (char *)malloc(100 * sizeof(char));
        printf("Informe a string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    printf("Strings desordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    quickSortStrings(strings, 0, n - 1);

    printf("\nStrings ordenadas usando Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
