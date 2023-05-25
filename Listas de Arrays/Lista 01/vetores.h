
void geraInteirosDe0aLimte(int vet[], int tamanho, int limite)
{
    int i;

    srand(time(NULL));

    for(i=0; i<tamanho; i++)
    {
        vet[i] = rand() % (limite + 1);
    }
}

void geraInteirosDe1aLimte(int vet[], int tamanho, int limite)
{
    int i;

    srand(time(NULL));

    for(i=0; i<tamanho; i++)
    {
        vet[i] = rand() % (limite) + 1;
    }
}


void mostraVetorInteiros(int vet[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%d\t", vet[i]);
    }
}
