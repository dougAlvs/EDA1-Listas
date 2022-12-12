#include <stdio.h>

int f91(int N)
{
    if (N >= 101)
    {
        return N - 10;
    }
    else
    {
        f91(f91(N + 11));
    }
}

int main(void)
{
    int N = 1;
    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
        {
            break;
        }
        int M = f91(N);
        printf("f91(%d) = %d\n", N, M);
    }

    return 0;
}