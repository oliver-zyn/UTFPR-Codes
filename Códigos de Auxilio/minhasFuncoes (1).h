int quadrado(int num)
{
    return(num * num);
}

void tabuada(int num)
{
    int i;

    for(i=0; i<=10; i++)
    {
        printf("%d * %d = %d\n", num, i, num*i);
    }
}

void soma(void) //sem parâmetros e sem retorno
{
    int num1, num2;

    printf("Informe o primeiro valor: ");
    scanf("%d",&num1);
    printf("Informe o segundo valor: ");
    scanf("%d",&num2);

    printf("Soma: %d\n", num1+num2);
}

int multiplica(void) //sem parâmetros e com retorno
{
    int num1, num2;

    printf("Informe o primeiro valor: ");
    scanf("%d",&num1);
    printf("Informe o segundo valor: ");
    scanf("%d",&num2);

    return(num1*num2);
}

float divide(int num1, int num2) //com parâmetros e com retorno
{
   return(num1/(float)num2);
}

int calculaFat(int num) //com parâmetros e com retorno
{
    int i, fat=1;

    for(i=num; i>=2; i--)
    {
        fat = fat * i;
    }
    return(fat);
}

void mostraFat(int num, int fat) //com parâmetros e sem retorno
{
    int i;

    printf("%d! = ", num);

    for(i=num; i>=2; i--)
    {
        printf("%d * ", i);
    }
    printf("1 = %d\n", fat);
}

int primo(int num) //com parâmetros e com retorno
{
    int i, contDiv=0;

    for(i=2; i<num; i++)
    {
        if(num%i == 0)
        {
            contDiv++;
            break;
        }
    }

    return(contDiv);
}
