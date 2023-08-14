int transformaCharEmInt(char texto[], int textoInt[]) {

    int i, size = 0, size1 = 0, charc, j = 0, sizeEspaco = 0;

    while (texto[size] != '\0') {
        if (texto[size] != ' ') {
            size++;
        } else {
            size++;
            sizeEspaco++;
        }
    }
    
    for(i = 0; i < size; i++) {
        if (texto[i] != ' ') {
            charc = texto[i];
            textoInt[j] = charc;
            j++;
        }
    }
    size1 = size - sizeEspaco;
    printf("size: %d, size1: %d, sizeEspaco: %d", size, size1, sizeEspaco);
    return size1;
}