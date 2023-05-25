int numeroAleatorio(int limite) {
    
    /* Gera 1 numero aleatorio na função. */
    
    int x;
    
    srand(time(NULL));
    x = rand() % limite;
    return x;
}

void randomArray(int array[], int size, int min, int max) {
    
    /* Atualiza um array passado, com numeros aleatorios gerados na função. */
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}