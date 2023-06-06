void contaVogais(int vetVogais[], char string[]) {
    
    int i;
    
    for(i=0; string[i]!='\0'; i++) {
        if (string[i] == 'a' || string[i] == 'A') {
            vetVogais[0]++;
        } else if (string[i] == 'e' || string[i] == 'E') {
            vetVogais[1]++;
        } else if (string[i] == 'i' || string[i] == 'I') {
            vetVogais[2]++;
        } else if (string[i] == 'o' || string[i] == 'O') {
            vetVogais[3]++;
        } else if (string[i] == 'u' || string[i] == 'U') {
            vetVogais[4]++;
        }
    }
    
    printf("\nVOGAL\t QUANTIDADE\n");
    printf("====================\n");
    printf("a/A\t\t%d\n", vetVogais[0]);
    printf("e/E\t\t%d\n", vetVogais[1]);
    printf("i/I\t\t%d\n", vetVogais[2]);
    printf("o/O\t\t%d\n", vetVogais[3]);
    printf("u/U\t\t%d\n", vetVogais[4]);
}