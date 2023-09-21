#include <stdio.h>
#include <string.h>

void Count(char s[], int *count) {
 char *R;
 R = s;
 while (*R != '\0') {
    *count += 1;
    R++;
 }
}

int main(void){
 int count = 0;
 char s[] = "bom dia";
 Count(s, &count);
 printf("%d", count);
}
