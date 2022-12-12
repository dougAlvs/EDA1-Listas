#include <stdio.h>
#include <string.h>

int main()
{
    int L;
    int Cc;
    int Cl;
    char cmd;
    int tamLinha;

    scanf("%i", &L);

    char texto[L][1001];

    for (int i = 0; i < L; i++)
    {
        scanf(" %999[^\n]", texto[i]);
    }

    scanf("%i %i", &Cl, &Cc);

    while (scanf(" %c", &cmd) > 0)
    {

        if (cmd == 'j')
        {

            if (Cl < L)
            {
                Cl++;
            }
        }
        else if (cmd == 'k')
        {

            if (Cl > 1)
            {
                Cl--;
            }
        }

        tamLinha = strlen(texto[Cl - 1]);
        if (Cc > tamLinha)
        {
            printf("%i %i %c\n", Cl, tamLinha, texto[Cl - 1][tamLinha - 1]);
        }
        else
        {
            printf("%i %i %c\n", Cl, Cc, texto[Cl - 1][Cc - 1]);
        }
    }
}