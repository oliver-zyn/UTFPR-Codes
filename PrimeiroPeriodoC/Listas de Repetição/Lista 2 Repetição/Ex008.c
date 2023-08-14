#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    int numeroConta, contaValida, inversoConta, digitoVerificador;
    int digito1, digito2, digito3, digito4, digito5;
    int somaDigitos = 0, somainvCorre = 0;
    int i;
    
    printf("Digite o numero da conta corrente: ");
    scanf("%i", &numeroConta);
    if (numeroConta >= 1000 && numeroConta <= 9999) {
        
        printf("CONTA: %i\n\n", numeroConta);
        
        digito1 = numeroConta / 1000;
        printf("Primeiro Digito: %i\n", digito1);
        digito2 = (numeroConta / 100) % 10;
        printf("Segundo Digito: %i\n", digito2);
        digito3 = (numeroConta / 10) % 10;
        printf("Terceiro Digito: %i\n", digito3);
        digito4 = numeroConta % 10;
        printf("Quarto Digito: %i\n\n", digito4);
        digito5 = digito4;
    
        contaValida = digito1 * 100 + digito2 * 10 + digito3;
        
        printf("Conta corrente: %i\n", contaValida);
    
        inversoConta = digito3 * 100 + digito2 * 10 + digito1;
        somainvCorre = contaValida + inversoConta;
        
        printf("Conta inversa: %i\n", inversoConta);
        printf("%i + %i = %i\n\n", contaValida, inversoConta, somainvCorre);
        
        digito1 = somainvCorre / 1000;
        printf("Primeiro Digito: %i\n", digito1);
        digito2 = (somainvCorre / 100) % 10;
        printf("Segundo Digito: %i\n", digito2);
        digito3 = (somainvCorre / 10) % 10;
        printf("Terceiro Digito: %i\n", digito3);
        digito4 = somainvCorre % 10;
        printf("Quarto Digito: %i\n\n", digito4);
        
        somaDigitos = digito1*0 + digito2*1 + digito3*2 + digito4*3;
        
        digitoVerificador = somaDigitos % 10;
        
        printf("x = %i\n\n", somaDigitos);
    
        for (i = 1; i <= 3; i++) {
            somainvCorre += (somainvCorre / (int)pow(10, i-1)) % 10 * i;
        }
    
        if (digitoVerificador == digito5) {
            printf("Conta valida. Digito verificador: %d\n", digitoVerificador);
        } else {
            printf("Conta invalida. Digito verificador incorreto.\n");
        }
    }

    

    return 0;
}