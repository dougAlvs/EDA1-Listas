

#include <stdio.h>
#include <string.h>

int main(void)
{
    char palavra[100];
    int nSim = 0, contador = 1, resultado = 0, triagemOk = 0;
    while (scanf("%s", palavra) == 1)
    {
        if (strcmp(palavra, "sim") == 0)
        {
            nSim++;
        }
        if (nSim >= 2 && triagemOk == 0)
        {
            triagemOk = 1;
            resultado += 1;
        }
        if (contador % 10 == 0)
        {
            nSim = 0;
            triagemOk = 0;
        }
        contador++;
    }
    printf("%d\n", resultado);
    return 0;
}