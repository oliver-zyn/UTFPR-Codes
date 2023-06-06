void contaAlfaDecimal(char string[]) {
    int i, countAlfa = 0, countDecimal = 0;
    
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z') {
            countAlfa++;
        } else if (string[i] >= '0' && string[i] <= '9') {
            countDecimal++;
        }
    }
    
    printf("Existem %d caracteres alfabeticos no texto.\n", countAlfa);
    printf("Existem %d caracteres numericos no texto.", countDecimal);
}