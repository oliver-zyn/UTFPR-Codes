void divisoresDeUmArraySemrepetidos(int vetor[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            printf("%d => ", vetor[i]);
            quaisDiv(vetor[i]);
            printf("-  %d Divisores\n", qtdDivisores(vetor[i]));
        }
    }
}