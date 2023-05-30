void geraVetorFloat0a1(float array[], int size) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = (float) rand() / RAND_MAX;
    }
}