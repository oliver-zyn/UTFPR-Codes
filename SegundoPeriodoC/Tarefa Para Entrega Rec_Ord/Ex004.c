#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Verifique se o filho esquerdo é maior que o nó raiz
    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    // Verifique se o filho direito é maior que o nó raiz
    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    // Se o maior não for o nó raiz, faça a troca
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        // Recursivamente chame heapify no nó afetado
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    // Construa um heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        // Mova o elemento raiz (maior) para o final do array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chame heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray nao ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    heapSort(arr, n);

    printf("\nArray ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
