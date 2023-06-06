#include <stdio.h>
#include "strings.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

int comparaString(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }

    return 0;
}

int main()
{
    char continuar;

    do {
        
        char string1[50], string2[50];
        int i = 0, j = 0;

        printf("Informe uma palavra: ");
        fgets(string1, sizeof(string1), stdin);
        
        string1[strcspn(string1, "\n")] = '\0';

        while(string1[i] != '\0') {
            i++;
        }
    
        i = i-1;
    
        for(i; i>=0; i--)
        {
            string2[j] = string1[i];
            j++;
        }
        
        string2[j] = '\0';
        
        printf("Palavra invertida: %s\n", string2);
        
        if (comparaString(string1, string2) == 1) {
            printf("Eh palindromo");
        } else {
            printf("Nao eh palindromo");
        }
        
        printf("\nDeseja repetir o programa (S/s)");
        scanf("%c", &continuar);
        limparBuffer();

    } while (continuar == 'S' || continuar == 's');

    return 0;
}