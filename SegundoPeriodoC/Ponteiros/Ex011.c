#include <stdio.h>
#include <string.h>

void imprimeString(char *s, int n) {
 char *c;
 for (c = s; c < s + n; c++)
 printf ("%c", *c);
}

int main(void){
 char s[] = "Bao Noite";
 imprimeString(s, strlen(s));
}
