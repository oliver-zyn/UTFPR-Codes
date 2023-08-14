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