#include <stdio.h>

int main(void)
{
    int diametro, A, L, P;
    scanf("%d", &diametro);
    scanf("%d %d %d", &A, &L, &P);
    if (A >= diametro && L >= diametro && P >= diametro)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}