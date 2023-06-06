#include <stdio.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

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

int main()
{
    char continuar;

    do {
        
        char string[50];

        printf("Informe um texto com ate 50 caracteres: ");
        fgets(string, sizeof(string), stdin);

        quebraLinha(string);

        printf("\nDeseja repetir o programa (S/s)");
        scanf("%c", &continuar);
        limparBuffer();

    } while (continuar == 'S' || continuar == 's');

    return 0;
}