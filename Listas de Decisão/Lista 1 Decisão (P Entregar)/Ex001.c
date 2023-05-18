#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    float salmin, salbruto, INSS, desc, salliq;
    
    printf("Informe o valor do salario minimo: ");
    scanf("%f", &salmin);
    printf("Informe o valor do salario bruto: ");
    scanf("%f", &salbruto);
    
    if ((salbruto / salmin) < 3) {
        INSS = 0.08;
        desc = salbruto * INSS;
        salliq = salbruto - desc;
        printf("Desconto do INSS: R$ %.2f\n", desc);
        printf("Salario Liquido: R$ %.2f", salliq);
    } else {
        INSS = 0.1;
        desc = salbruto * INSS;
        salliq = salbruto - desc;
        if (desc > salmin) {
            desc = salmin;
            salliq = salbruto - desc;
            printf("Desconto do INSS: R$ %.2f\n", desc);
            printf("Salario Liquido: R$ %.2f", salliq);
        } else {
            printf("Desconto do INSS: R$ %.2f\n", desc);
            printf("Salario Liquido: R$ %.2f", salliq);
        }
         
    }
    return 0;
}