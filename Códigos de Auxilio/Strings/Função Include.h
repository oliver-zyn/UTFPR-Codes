int Includes(char string[], char substring[]) {

    int resultado = 0, i = 0, j;

    while(string[i] != '\0') {
        if (string[i] == substring[0]) {
            j = 0;
            while (substring[j] != '\0' && string[i] != '\0') {
                if (string[i] != substring[j]) {
                    break;
                }
                i++;
                j++;
            }
            if (substring[j] == '\0') {
                resultado = 1;
            }
        }
        i++;
    }
    return resultado;
}