#include <string.h>

void contaVogais(int vetVogais[], char string[]) {
    
    int i;
    
    for(i=0; string[i]!='\0'; i++) {
        if (string[i] == 'a' || string[i] == 'A') {
            vetVogais[0]++;
        } else if (string[i] == 'e' || string[i] == 'E') {
            vetVogais[1]++;
        } else if (string[i] == 'i' || string[i] == 'I') {
            vetVogais[2]++;
        } else if (string[i] == 'o' || string[i] == 'O') {
            vetVogais[3]++;
        } else if (string[i] == 'u' || string[i] == 'U') {
            vetVogais[4]++;
        }
    }
    
    printf("\nVOGAL\t QUANTIDADE\n");
    printf("====================\n");
    printf("a/A\t\t%d\n", vetVogais[0]);
    printf("e/E\t\t%d\n", vetVogais[1]);
    printf("i/I\t\t%d\n", vetVogais[2]);
    printf("o/O\t\t%d\n", vetVogais[3]);
    printf("u/U\t\t%d\n", vetVogais[4]);
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

int comparaString(char string1[], char string2[]) {
    int resultado = strcmp(string1, string2);
    
    if (resultado == 0) {
        resultado = 1;
    } else {
        resultado = 0;
    }
    
    return resultado;
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

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

