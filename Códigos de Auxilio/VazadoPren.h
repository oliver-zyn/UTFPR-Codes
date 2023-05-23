void vazado(int num, char opcao) {
    
    int i, y, j;
    
    if (opcao == 'P' || opcao == 'p') {
        for (i = 1; i<=num + 1; i++) {
            for (y = 1; y < i; y++) {
                printf("*");
            }
        printf("\n");
        }
    } else if (opcao == 'V' || opcao == 'v'){
        for (i = 0; i < num; i++) {
            if (i == num - 1) {
                for (y = 0; y <= i; y++) {
                    printf("*");
                }
            } else {
                for (y = 0; y <= i; y++) {
                    if (y == 0 || y == i) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
        printf("\n");
        }
    }

}