void paresDeUmArraySemrepetidos(int vetor[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            printf("%d => ", vetor[i]);
            paresAteUmNumero(vetor[i]);
            printf("Soma = %d\n", somaDePares(vetor[i]));
        }
    }
}