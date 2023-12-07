 #include <stdio.h>

void imprimeTriangulo(int n, char caractere, int n1) {
    if (n > 0) {
        for (int i = 0; i < n - 1; i++) {
            printf(" ");  
        }
        for (int i = 0; i < n1; i++) {
            printf("%c", caractere);  
        }
        printf("\n"); 
        imprimeTriangulo(n - 1, caractere, n1 + 1);
    }
}

int main() {
    int numeroDeLinhas;
    char caractere;

    printf("Número de linhas: ");
    scanf("%d", &numeroDeLinhas);

    printf("Caractere: ");
    scanf(" %c", &caractere);

    imprimeTriangulo(numeroDeLinhas, caractere, 1);

    return 0;
} 