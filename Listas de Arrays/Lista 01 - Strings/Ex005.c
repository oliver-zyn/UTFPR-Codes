#include <stdio.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

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

int main()
{
    char continuar;

    do {
        
        char string[100];
        
        printf("Informe um texto com ate 100 caracteres: ");
        fgets(string, sizeof(string), stdin);

        contaAlfaDecimal(string);

        printf("\nDeseja repetir o programa (S/s)");
        scanf("%c", &continuar);
        limparBuffer();

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
