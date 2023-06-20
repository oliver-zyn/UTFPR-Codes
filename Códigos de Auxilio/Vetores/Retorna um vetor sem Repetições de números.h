int noReps(int vetors[], int size) {

    int i = 0, j = 0;
    int vetorR[50];

    for (i = 0; i < size; i++) {
        if (i == 0 || vetors[i] != vetors[i-1]) {
            vetorR[j] = vetors[i];
            j++;
        }
    }

    for(i = 0; i < size; i++) {
        if (vetorR[i] != '\0') {
            vetors[i] = vetorR[i];
        } else {
            vetors[i] = '\0';
        }
    }
    return j;
}