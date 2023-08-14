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