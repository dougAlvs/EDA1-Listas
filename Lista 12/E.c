#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct fila_st
{
    Item *v;
    int size,
        ini,
        fim,
        ocupados;
}fila;

int inicializa_fila(fila *f, int s)
{
    f -> size = s;
    f -> v = malloc(s * sizeof(Item));
    if (f -> v == NULL) return 0;
    f -> ini = -1;
    f -> fim = 0;
    f -> ocupados = 0;
    return 1;
}

int enfileira(fila *f, Item e)
{
    if (f -> ocupados >= f -> size) return 0;
    f -> v[f -> fim] = e;
    f -> fim = (f -> fim + 1) % f -> size;
    f -> ocupados++;
    return 1;
}

Item espia(fila *f)
{
    return f -> v[(f -> ini + 1) % f -> size];  
}

int fila_vazia(fila *f)
{
    return f -> ocupados == 0;
}

void desinfileira(fila *f)
{
    f -> ocupados--;
    f -> ini = (f -> ini + 1) % f -> size;
}

void limpa_fila(fila *f)
{
    free(f -> v);
    f -> size = 0;
}

int main(void)
{
    int N;
    scanf("%d", &N);
    fila f;
    inicializa_fila(&f, N);
    Item *descartados = calloc(N - 1, sizeof(Item));
    for (int i = 1; i <= N; i++)
    {
        enfileira(&f, i);
    }
    for (int i = 0; i < N - 1; i++)
    {
        descartados[i] = espia(&f);
        desinfileira(&f);
        enfileira(&f, espia(&f));
        desinfileira(&f);
    }
    printf("Cartas descartadas:");
    for (int i = 0; i < N - 1; i++)
    {
        printf(i != N - 2 ? " %d," : " %d\n", descartados[i]);
    }
    printf("Carta restante: %d\n", espia(&f));
    free(descartados);
    limpa_fila(&f);
    
    return 0;
}