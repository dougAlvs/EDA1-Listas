#include <stdio.h>

int somar(unsigned long long int N)
{
    if (N < 10) return N;
    return (N % 10) + somar(N/10);
}

int main(void)
{
    unsigned long long int N;
    int soma;
    scanf("%llu", &N);
    soma = somar(N);
    printf("%d\n", soma);
    return 0;
}
