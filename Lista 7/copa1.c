#include <stdio.h>

char vencedorCopa(int *M, int *N) 
{
    char oitavas[8], quartas[4], semi[2];
    for (int i = 0, j = 0; i < 8; i++, j += 2)
    {
        if (*(M + i) > *(N + i)) oitavas[i] = 65 + j;
        else oitavas[i] = 66 + j;
    }
    for (int i = 8, j = 8; i < 12; i++, j += 2)
    {
        if (*(M + i) > *(N + i)) quartas[i - 8] = oitavas[j - 8];
        else quartas[i - 8] = oitavas[j - 7];
    }
    for (int i = 12, j = 12; i < 14; i++, j += 2)
    {
        if (*(M + i) > *(N + i)) semi[i - 12] = quartas[j - 12];
        else semi[i - 12] = quartas[j - 11];
    }
    if (*(M + 14) > *(N + 14)) printf("%c\n", semi[0]);
    else printf("%c\n", semi[1]);
}

int main(void)
{
    int M[15], N[15];
    for (int i = 0; i < 15; i++)
    {
        scanf("%d %d", &M[i], &N[i]);
    }
    vencedorCopa(M, N);
    return 0;
}