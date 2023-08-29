#include <stdio.h>
void soma(int a, int b, int *R) {
 *R = a + b;
}
int main(void){
 int a = 10, R = 0;
 int b = 20;
 soma(a, b, &R);
 printf("a: %d, b: %d, Resultado: %d\n", a, b, R);
}