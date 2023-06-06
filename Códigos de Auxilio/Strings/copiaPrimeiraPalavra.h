
void copiaPrimeiraPalavra(char string[]) {
    int i, j = 0, y = 0, primeiroEspaco = 0;
    char stringPalavra[50];
    
    for (i = 0; string[i] != '\0'; i++) {
        
        if (primeiroEspaco == 0) {
            while (string[i] == ' ') {
                i++;
            }
        }
        
        primeiroEspaco = 1;
        
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
        