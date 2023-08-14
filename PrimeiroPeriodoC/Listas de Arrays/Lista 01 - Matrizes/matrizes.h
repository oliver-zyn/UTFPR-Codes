void gerarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna], int limite) {

    srand(time(NULL));

    for (int j = 0; j < linha; j++) {
        for (int i = 0; i < coluna; i++) {
            matriz[j][i] = (rand() % limite) + 1;
        }
    }
}

void gerarMatrizInteiroPreenchida(int linha, int coluna, int matriz[linha][coluna], int num) {

    for (int j = 0; j < linha; j++) {
        for (int i = 0; i < coluna; i++) {
            matriz[j][i] = num;
        }
    }
}

void mostrarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna]) {

    for (int j = 0; j < linha; j++) {
        for (int i = 0; i < coluna; i++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}

void mostraVetorInteiros(int vet[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%d ", vet[i]);
    }
}

int calcularPotencia(int base, int expoente) {

    int resultado = 1;

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

void calculaPotenciaPorVetores(int vetorbase[], int vetorexpoente[], int vetorResultado[], int tamanho) {

    printf("BASE\tEXPOENTE\tRESULTADO\n");
    for (int i = 0; i < tamanho; i++) {
        int base = vetorbase[i];
        int expoente = vetorexpoente[i];
        vetorResultado[i] = calcularPotencia(base, expoente);
        printf("%d\t%d\t\t%d\n", base, expoente, vetorResultado[i]);
    }
}

