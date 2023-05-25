#include <string.h>

//o parametro deve ser passado como string (ex: "5005")

int isPalindrome(const char *str) {
    int len = strlen(str);
    
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // não é palíndromo
        }
    }
    
    return 1; // é palíndromo
}
