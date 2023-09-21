#include <stdio.h>
void troca(int *a, int *b) {
 int t = 0;
 t = *a;
 *a = *b;
 *b = t;
}
int main(void){
 int a = 10;
 int b = 20;
 printf("a: %d, b: %d\n", a, b);
 troca(&a, &b);
 printf("a: %d, b: %d\n", a, b);
}