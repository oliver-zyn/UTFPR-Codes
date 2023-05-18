#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    
    float altura, menorAltura, maiorAltura, countM, countF, somaM, somaF, total, percM, percF;
    char continuar[] = "", sexo[] = "";
    
    do {
	  menorAltura = 10;
    	  maiorAltura = 0;

        do {
            printf("Informe a altura: ");
            scanf("%f", &altura);
            
            if (altura == 0) {
                break;
            }
            
            printf("Informe o sexo: ");
            scanf(" %c", sexo);
            
            if (strcmp("m", sexo) == 0 || strcmp("M", sexo) == 0) {
                countM++;
                somaM += altura;
            }
        
            if (strcmp("f", sexo) == 0 || strcmp("F", sexo) == 0) {
                countF++;
                somaF += altura;
            }
            
            if (altura > maiorAltura) {
                maiorAltura = altura;
            }
            
            if (altura < menorAltura) {
                menorAltura = altura;
            }
            
        } while (altura != 0);
        
        total = countF + countM;
        percM = countM / total * 100;
        percF = countF / total * 100;
        
        printf("==== MULHERES ====\n");
        printf("Quantidade: %.0f\n", countF);
        printf("Media de altura: %.2f\n", somaF / countF);
        printf("Percentual: %.2f\n\n", percF);
        
        printf("===== HOMENS =====\n");
        printf("Quantidade: %.0f\n", countM);
        printf("Media de altura: %.2f\n", somaM / countM);
        printf("Percentual: %.2f\n\n", percF);
        
        printf("\n Deseja repetir o programa (S ou N)? ");
        scanf(" %c", continuar);
        
    } while (strcmp("S", continuar) == 0);
    
    return 0;
}