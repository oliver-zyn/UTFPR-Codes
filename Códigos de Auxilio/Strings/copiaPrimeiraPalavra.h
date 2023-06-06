void copiaPrimeiraPalavra(char string[]) {
    int i, j = 0;
    char stringPalavra[50];
    
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ' && string[i] != '\n') {
            stringPalavra[j] = string[i];
            j++;
        } else {
            break;
        }
    }
    
    stringPalavra[j] = '\0';
    printf("%s\n", stringPalavra);
}