#include <stdio.h>

int main()
{
    char continuar;

    do {
        
        int nums[10], countPar, countImpar, i;
        float percentPar, percentImpar;
        
        for(i = 0; i < 10; i++) {
            printf("Informe o valor para a posicao %d do vetor: ", i);
            scanf("%d", &nums[i]);
        }
        
        printf("==== PARES ====\n");
        
        for(i = 0; i < 10; i++) {
            if (nums[i] % 2 == 0) {
                countPar++;
                printf("nums[%d] = %d <-- %do numero par\n", i, nums[i], countPar);
            }
        }
        
        printf("==== IMPARES ====\n");
        
        for(i = 0; i < 10; i++) {
            if (nums[i] % 2 != 0) {
                countImpar++;
                printf("nums[%d] = %d <-- %do numero impar\n", i, nums[i], countImpar);
            }
        }
        
        percentPar = (float) countPar * 100 / 10;
        percentImpar = (float) countImpar * 100 / 10;
        
        printf("\nExistem %d numeros pares no vetor, ou seja, %.2f%%", countPar, percentPar);
        printf("\nExistem %d numeros impares no vetor, ou seja, %.2f%%", countImpar, percentImpar);

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    return 0;
}
