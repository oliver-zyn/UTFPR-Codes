#include <stdio.h>
#include <string.h>

void copia_string(char *destino, char *origem, int n) {
    char *c;
    for (c = origem; c < origem + n; c++) {
        *destino = *c;
        destino++;
    }
    *destino = '\0';
}

int main(void){
    char origem[] = "Bom?", destino[] = "";
    copia_string(destino, origem, strlen(origem));
    printf("%s", destino);
}


