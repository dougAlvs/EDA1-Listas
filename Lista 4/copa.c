#include <stdio.h>

int main(void)
{
    int T, N;
    while (1)
    {
        scanf("%d %d", &T, &N);
        if (T == 0)
        {
            break;
        }
        int nEmpates = N * 3;
        for (int i = 0; i < T; i++)
        {
            char times[11];
            int pontos;
            scanf("%s %d", times, &pontos);
            nEmpates -= pontos;
        }
        printf("%d\n", nEmpates);
    }
    return 0;
}
