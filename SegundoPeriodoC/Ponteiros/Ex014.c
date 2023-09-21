#include <stdio.h>
#include <string.h>

void concatena_strings(char *sa, char *sb) {
    char *c;
    sa += strlen(sa);
    for (c = sb; c < sb + strlen(sb); c++) {
        printf("%c\n", *c);
        *sa = *c;
        sa++;
    }
}

int main(void){
    char sa[] = "Bom?", sb[] = " Dia";
    printf("%s\n", sa);
    concatena_strings(sa, sb);
    printf("%s", sa);
}