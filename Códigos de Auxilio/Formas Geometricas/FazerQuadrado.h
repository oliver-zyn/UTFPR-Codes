void quadrado(int numLinhas, int numColunas, int caractere) {
    
    int i, count;
    
    for (i = 0; i < (numColunas * numLinhas); i++) {
        if (count == numColunas - 1) {
            printf("%c\n", caractere);
            count = 0;
        } else {
            printf("%c ", caractere);
            count++;
        }
    }
}