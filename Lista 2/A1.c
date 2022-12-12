#include <stdio.h>

int main(void)
{
    int N, T, soma = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d",&x);
        soma += x;
    }    
    scanf("%d", &T);
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