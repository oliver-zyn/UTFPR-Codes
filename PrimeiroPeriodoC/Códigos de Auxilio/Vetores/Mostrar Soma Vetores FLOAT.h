void mostraSomaVetorFloat(float vet[], int tamanho)
{
    int i;
    float soma = 0;
    
    for(i=0; i<tamanho; i++){
        soma += vet[i];
    }
    printf("\nSoma: %.2f", soma);
}