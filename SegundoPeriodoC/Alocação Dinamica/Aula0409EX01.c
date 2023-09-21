#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inverte_string(char s[]) {
    int i, j = 0, t;
    t = strlen(s);
    char *sinv = malloc(t * sizeof(char));

    for (i = t-1; i>=0; i--) {
        sinv[j] = s[i];
        j++;
    }
    sinv[j] = '\0';
    printf("Dentro da funcao: %s\n", sinv);
    return sinv;
}

int main(void) {
    char *texto = "Pedro bacana";
    printf("Texto da funcao:  %s\n\n", texto);
    char *texto_inv = inverte_string(texto);

    printf("Fora da funcao:   %s", texto_inv);
}
