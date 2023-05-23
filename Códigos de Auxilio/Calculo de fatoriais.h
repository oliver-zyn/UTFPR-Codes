int calculaFat(int num) //com par�metros e com retorno
{
    int i, fat=1;

    for(i=num; i>=2; i--)
    {
        fat = fat * i;
    }
    return(fat);
}

void mostraFat(int num, int fat) //com par�metros e sem retorno
{
    int i;

    printf("%d! = ", num);

    for(i=num; i>=2; i--)
    {
        printf("%d * ", i);
    }
    printf("1 = %d\n", fat);
}