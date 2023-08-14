
void quebraLinha(char string[]) {
    int i, j = 0, primeiroEspaco = 0;
    char palavra[50];

    printf("\n==== TEXTO NA VERTICAL ====\n");

    for (i = 0; string[i] != '\0'; i++) {
        if (primeiroEspaco == 0) {
            while (string[i] == ' ') {
                i++;
            }
        }

        primeiroEspaco = 1;

        if (string[i] != ' ' && string[i] != '\n') {
            palavra[j] = string[i];
            j++;
        } else {
            palavra[j] = '\0';
            printf("%s\n", palavra);
            j = 0;
        }
    }

    palavra[j] = '\0';
    printf("%s", palavra);
}
        