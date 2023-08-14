int calcularRetangular(int num) {
    
    int i = 2, n3 = 0, j, y;
    
    for (i; n3 < num; i += 2) {
        n3 += i;
        j = i;
    }
    if (n3 == num) {
        for (y = 2; y <= num; y += 2) {
            if (y < j) {
                printf("%d + ", y);
            } else if (y == j) {
                printf("%d = %d ==> Eh retangular", y, num);
            }
        }
        return 1;
    } else if (n3 > num){
        printf("%d nao eh retangular", num);
        return 0;
    }
}

void calcularRetangularComIntervalo(int inferior, int superior) {
    
    int i = 2, n3 = 0, j, y;
    
    for (inferior; inferior <= superior; inferior++) {
        for (i; n3 < inferior; i += 2) {
            n3 += i;
            j = i;
        }
        if (n3 == inferior) {
            for (y = 2; y <= inferior; y += 2) {
                if (y < j) {
                    printf("%d + ", y);
                } else if (y == j) {
                    printf("%d = %d ==> Eh retangular!\n", y, inferior);
                }
            }
        }
    }
}