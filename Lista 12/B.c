#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    while (scanf("%d", &N) == 1)
    {
        int *esq = calloc(61 , sizeof(int));
        int *dir = calloc(61 , sizeof(int));
        int pares = 0;
        for (int i = 0; i < N; i++)
        {
            char lado;
            int num;
            scanf("%d %c", &num, &lado);
            if (lado == 'D')
            {
                dir[num]++;
            }
            if (lado == 'E')
            {
                esq[num]++;
            }
            if (dir[num] && esq[num])
            {
                dir[num]--;
                esq[num]--;
                pares++;
            }
        }
    printf("%d\n", pares);
    free(dir);
    free(esq);
    }
    
    return 0; 
}   
    