#include <stdio.h>
#include <stdlib.h>

void penalti(char *A, char *B, int N)
{
    int saldoA = 0, saldoB = 0, contA = 0, contB = 0;
    for (int i = 0; i < N; i++)
    { 
        if (*(A + i) == 'o')
        {
            saldoA++;
            contA++;
        } 
        if ((saldoA + (N - contA) < saldoB || saldoB + (N - contB) < saldoA) || (contA + contB == 2 * N && (saldoA == 0 || saldoB == 0)))
        {
            printf("%d\n", contA + contB);
            return;
        }
        if (*(B + i) == 'o')
        {
            saldoB++;
            contB++;
        }
        if ((saldoA + (N - contA) < saldoB || saldoB + (N - contB) < saldoA) || (contA + contB == 2 * N && (saldoA == 0 || saldoB == 0)))
        {
            printf("%d\n", contA + contB);
            return;
        }
        if (*(A + i) == 'x')
        {
            contA++;
        }
        if ((saldoA + (N - contA) < saldoB || saldoB + (N - contB) < saldoA) || (contA + contB == 2 * N && (saldoA == 0 || saldoB == 0)))
        {
            printf("%d\n", contA + contB);
            return;
        }
        if (*(B + i) == 'x')
        {
            contB++;
        }
        if ((saldoA + (N - contA) < saldoB || saldoB + (N - contB) < saldoA) || (contA + contB == 2 * N && (saldoA == 0 || saldoB == 0)))
        {
            printf("%d\n", contA + contB);
            return;
        }
        if (((saldoA == saldoB) && (saldoA != 0 || saldoB != 0)) && contA + contB == 2 * N)
        {
            printf("Empate\n");
            return;
        }
    }
}

int main (void)
{
    int N;
    char *A = calloc(N + 1, sizeof(char));
    char *B = calloc(N + 1, sizeof(char));
    scanf("%d", &N);
    scanf("%s %s", A, B);
    penalti(A, B, N);
    return 0;
}