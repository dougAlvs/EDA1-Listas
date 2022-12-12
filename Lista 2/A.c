#include <stdio.h>

int main(void)
{
    int a, b, c, T;
    scanf("%d %d %d %d", &a, &b, &c, &T);
    int soma = a + b + c;
    if (soma == T)
    {
        printf("Acertou\n");
    }
    else
    {
        printf("Errou\n");
    }
    return 0;
}