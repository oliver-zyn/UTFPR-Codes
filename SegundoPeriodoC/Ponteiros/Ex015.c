#include <stdio.h>
#include <string.h>

int compara_string(char *sa, char *sb) {
    char *c;
    for (c = sa; c < sa + strlen(sa); c++) {
        if (*sb != *c) {
            return 0;
        }
        sb++;
    }
    return 1;
}

int main(void){
    char sa[] = "Bom?", sb[] = "Bom?";
    int R = compara_string(sa, sb);
    printf("%d", R);
}