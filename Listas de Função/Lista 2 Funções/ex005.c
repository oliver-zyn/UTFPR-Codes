#include <stdio.h>

int calcularQuadradoDigitos(int numero) {
    int somaQuadrados = 0, proxDigito = 0;
    while (numero > 0) {
        int digito = numero % 10;
        int proxDigito = numero / 10;
        somaQuadrados += digito * digito;
        numero /= 10;
    }
    return somaQuadrados;
}

int ehFeliz(int numero) {
    for (int i = 0; i < 20; i++) {
        numero = calcularQuadradoDigitos(numero);
        if (numero == 1) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i;
    char continuar;
    
    do {
        
       for (i = 1; i <= 500; i++) {
           
           if (ehFeliz(i) == 1) {
                printf("%d\t", i);
           }

       }

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');
    
    return 0;
}
