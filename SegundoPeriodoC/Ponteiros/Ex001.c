#include <stdio.h>
#include <string.h>
void main(void) {
 int v[] = {1, 2, 3, 4, 5};
 char s[] = "ola";
 int i = 0;
 for(i = 0; i < 5; i++) {
 printf("valor: %d, end.: %ld\n", v[i], &v[i]);
 }
 printf("\n");
 for(i = 0; i < strlen(s); i++) {
 printf("valor: %c, end.: %ld\n", s[i], &s[i]);
 }
}
