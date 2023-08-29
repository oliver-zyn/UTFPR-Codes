#include <stdio.h>
#include <string.h>

void imprimeInteiro(int *s, int n) {
 int *c;
 for (c = s; c < s + n; c++)
 printf("%d ", *c);
}

int main(void){
 int s[2] = {2,4};
 imprimeInteiro(s, 2);
}
