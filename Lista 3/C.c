#include <stdio.h>
#include <string.h>

int grau9(int N)
{
    if (N < 10)
    {
        if (N == 9)
        {
            return 1;
        }
        return 0;
    }
    int grau = grau9(somaint(N));
    if (grau == 0)
    {
        return 0;
    }
    return grau + 1;
}

int somachar(char N[1001])
{
    int soma = 0;
    for (int i = strlen(N) - 1; i >= 0; i--)
    {
        soma += *(N + i) - 48;
    }
    return soma;
}

int somaint(int N)
{
    if (N < 10)
        return N;
    return N % 10 + somaint(N / 10);
}

int main(void)
{
    while (1)
    {
        char N[1001];
        scanf("%s", N);
        if (N[0] == '0') break;
        int somaInicial = somachar(N);
        int grau = grau9(somaInicial);
        if (grau != 0)
        {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", N, grau);
        }
        else
        {
            printf("%s is not a multiple of 9.\n", N);
        }
    }
    return 0;
}