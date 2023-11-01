#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[200], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
}

void selectionSort(int v[200], int n) {
    int i, j, aux, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        aux = v[i];
        v[i] = v[min];
        v[min] = aux; 
    }
}

void bubbleSort(int v[200], int n) {
    int i, j, aux;
    for (i = n-1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux; 
            }
        }
    }
}

void quickSort(int vet[], int esq, int dir) {
    int pivo = esq, i, ch, j;
    for (i = esq + 1; i <= dir; i++) {
        j = i;
        if (vet[j] < vet[pivo]) {
            ch = vet[j];
            while (j > pivo) {
                vet[j] = vet[j-1];
                j--;
            }
            vet[j] = ch;
            pivo++;
        }
    }
    if (pivo-1 >= esq) {
        quickSort(vet, esq, pivo -1);
    }
    if (pivo + 1 <= dir) {
        quickSort(vet, pivo+1, dir);
    }
}

void mergeSort(int *vetor, int posicaoInicio, int posicaoFim) {
    int i, j, k, metadeTamanho, *vetorTemp;
    if (posicaoInicio == posicaoFim)
        return;
    metadeTamanho = (posicaoInicio + posicaoFim) / 2;
    mergeSort(vetor, posicaoInicio, metadeTamanho);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim);
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));
    while (i < metadeTamanho + 1 || j < posicaoFim + 1) {
        if (i == metadeTamanho + 1) {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        } else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            } else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for (i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}


int main()
{
    int v[200], vOrd[200], n, i, opcao;

    printf("Entre com o tamanho desejado do vetor: ");
    scanf("%d", &n);
    printf("Informe os %d elementos do vetor: \n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    do {
        for (i = 0; i < n; i++) {
            vOrd[i] = v[i];
        }

        printf("\nOpcoes de algoritmos de ordenacao:\n");
        printf("1 - Insercao \n2- Selecao \n3 - Bolha \n4 - QuickSort \n5 - MergeSort\n");
        printf("Indique um numero de algoritmo ou 0 para sair: \n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            insertionSort(vOrd, n);
            break;
        case 2:
            selectionSort(vOrd, n);
            break;
        case 3:
            bubbleSort(vOrd, n);
            break;
        case 4:
            quickSort(vOrd, 0, n-1);
            break;
        case 5:
            mergeSort(vOrd, 0, n-1);
            break;
        case 0:
            break;
        }

        printf("\nVetor original:\n");
        for (i = 0; i < n; i++) {
            printf("%d\t", v[i]);
        }

        printf("\nVetor ordenado:\n");
        for (i = 0; i < n; i++) {
            printf("%d\t", vOrd[i]);
        }
        printf("\n");
    }
    while (opcao != 0);

    return 0;
}
