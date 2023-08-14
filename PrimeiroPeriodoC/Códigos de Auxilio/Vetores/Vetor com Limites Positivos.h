void gerarVetorComLimitesPositivos(int array[], int size, int min, int max) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}