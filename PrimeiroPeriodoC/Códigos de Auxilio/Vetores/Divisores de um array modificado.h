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