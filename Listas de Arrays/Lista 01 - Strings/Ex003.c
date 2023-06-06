#include <stdio.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

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

int main()
{
    char continuar;

    do {
        
        char string[50];

        printf("Informe um texto com ate 50 caracteres: ");
        fgets(string, sizeof(string), stdin);

        copiaPrimeiraPalavra(string);

        printf("\nDeseja repetir o programa (S/s)");
        scanf("%c", &continuar);
        limparBuffer();

    } while (continuar == 'S' || continuar == 's');

    return 0;
}