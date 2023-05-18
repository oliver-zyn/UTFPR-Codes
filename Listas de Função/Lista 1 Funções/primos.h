#include <stdio.h>

int primo(int num) {
    
    int i = 2, cont = 0, result;
    
    for (i; i<=num / 2; i++) {
        if (num%i == 0) {
            cont++;
            break;
        }
        if (cont > 1) {
            cont++;
        }
    }
    return cont;
}