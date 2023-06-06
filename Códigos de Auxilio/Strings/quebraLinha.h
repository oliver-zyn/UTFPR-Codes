void quebraLinha(char string[]) {
    
    int i, j = 0, y;
    char stringPalavras[50];
    
    printf("\n==== TEXTO NA VERTICAL ====\n");
    
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ' && string[i] != '\n') {
            stringPalavras[j] = string[i];
            j++;
        } else {
            printf("%s\n", stringPalavras);
            for (y = 0; y < j; y++) {
                stringPalavras[y] = '\0';
            }
            j = 0;
        }
    }
    
    printf("%s", stringPalavras);

}
