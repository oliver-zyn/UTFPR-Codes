int somaDiv(int num) {
    
    int i, soma = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            soma += i;
        }
    }
    
    return soma;
}