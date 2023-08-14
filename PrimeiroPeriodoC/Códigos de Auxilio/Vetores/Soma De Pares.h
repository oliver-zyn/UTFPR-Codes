int somaDePares(int num) {
    
    int i, cont = 0;
    
    for (i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            cont += i;
        }
    }
    return cont;
}