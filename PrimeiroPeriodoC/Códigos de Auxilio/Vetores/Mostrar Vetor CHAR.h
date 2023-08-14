void mostraVetorChar(char vet[], int tamanho, int num)
{
    int i, j = 0;

    for(i=0; i<tamanho; i++) {
        if (j < num - 1) {
            printf("%c ", vet[i]);
            j++;
        } else if (j == num - 1) {
            printf("%c\n", vet[i]);
            j = 0;
        }
    }
}