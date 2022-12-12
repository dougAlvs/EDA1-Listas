#include <stdio.h>

int soma = 0, i = 0;

void somar(int *valores, int limite, int contador)
{
    if (i == contador) return;
    i++;
    soma += *valores;
    if (soma > limite)
    {
        soma = 0;
        somar(valores + 1, limite, contador);
        printf("%d\n", *valores);
    }
    somar(valores + 1, limite, contador);
}

int main(void)
{
    int valores[1000], contador = 0, limite;
    while (1)
    {
        scanf("%d", &valores[contador]);
        if (valores[contador] == 0) break;
        contador++;
    }
    scanf("%d", &limite);
    somar(valores, limite, contador);

    return 0;
}