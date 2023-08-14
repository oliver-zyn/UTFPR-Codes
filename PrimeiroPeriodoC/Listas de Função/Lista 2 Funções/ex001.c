#include <stdio.h>

void numeroEquivaleSomaImpares (int num) {
    
    int i, soma = 0, resultado = 0;
    
    printf("%d = ", num);
    
    for(i = 1; i <= num; i += 2) {
        
        soma += i;
        printf("%d ", i);
        
        if (soma == num) {
            resultado++;
            break;
        } else if (soma > num) {
            break;
        }
        
    }
    
    if (resultado != 0) {
            printf("=> Soma = %d => Equivale a soma dos impares\n", soma);
        } else {
            printf("=> Soma = %d => Nao equivale a soma dos impares\n", soma);
    }
    
}

void numeroEquivaleSomaImparesIntervalo(int inferior, int superior) {
    
    int i;
    
    for (i = inferior; i <= superior; i++) {
        numeroEquivaleSomaImpares(i);
    }
}

int main()
{
    
    int num, opcao, inferior, superior;
    char continuar;
    
    do {
        
        printf("1 - Verifica se o numero equivale a soma dos impares\n");
        printf("2 - Verifica se os numeros no intervalo equivalem a soma dos impares\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
            
                printf("Informe um numero: ");
                scanf("%d", &num);
                
                numeroEquivaleSomaImpares(num);
                break;
                
            case 2:
            
                printf("Informe o valor do limite inferior de um intervalo: ");
                scanf("%d", &inferior);
                
                printf("Informe o valor do limite superior de um intervalo: ");
                scanf("%d", &superior);
            
                numeroEquivaleSomaImparesIntervalo(inferior, superior);
                break;
            
            default:
            
                printf("Escolha uma opcao valida!");
                break;
                
        }
        

        printf("\nDeseja repetir o programa (S/s)");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');
    
    return 0;
}
