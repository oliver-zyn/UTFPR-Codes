 #include <stdio.h>
//#include "strings.h"

void contaVogais(int vetVogais[], char string[])
{

    int i;

    for(i=0; string[i]!='\0'; i++)
    {
        if (string[i] == 'a' || string[i] == 'A')
        {
            vetVogais[0]++;
        }
        else if (string[i] == 'e' || string[i] == 'E')
        {
            vetVogais[1]++;
        }
        else if (string[i] == 'i' || string[i] == 'I')
        {
            vetVogais[2]++;
        }
        else if (string[i] == 'o' || string[i] == 'O')
        {
            vetVogais[3]++;
        }
        else if (string[i] == 'u' || string[i] == 'U')
        {
            vetVogais[4]++;
        }
    }
    printf("\nVOGAL\tQUANTIDADE\n");
    printf("==================\n");
    printf("A/a\t    %d\n", vetVogais[0]);
    printf("E/e\t    %d\n", vetVogais[1]);
    printf("I/i\t    %d\n", vetVogais[2]);
    printf("O/o\t    %d\n", vetVogais[3]);
    printf("U/u\t    %d\n", vetVogais[4]);
}

int main()
{
    char continuar;

    do
    {

        char string[100];
        int vetVogais[5] = {0, 0, 0, 0, 0};

        printf("Informe um texto com ate 100 caracteres: ");
        fflush(stdin);
        gets(string);

        contaVogais(vetVogais, string);

        printf("\nDeseja repetir o programa (S/s)");
        scanf("%c", &continuar);
        fflush(stdin);

    }
    while (continuar == 'S' || continuar == 's');

    return 0;
} 