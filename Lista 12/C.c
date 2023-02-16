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
    int P, R, cont = 1;
    while (1)
    {
        scanf("%d %d", &P, &R);
        if (P == 0 && R == 0) break;
        fila f;
        inicializa_fila(&f, P);

        for (int i = 0; i < P; i++)
        {
            Item x;
            scanf("%d", &x);
            enfileira(&f, x);
        }
        
        for (int i = 0; i < R; i++)
        {
            int N, J;
            scanf("%d %d", &N, &J);
            for (int i = 0; i < N; i++)
            {
                int acao;
                scanf("%d", &acao);
                Item e = espia(&f);
                desinfileira(&f);
                if (acao == J) enfileira(&f, e);
            }            
        }
        printf("Teste %d\n%d\n", cont++, espia(&f));
        limpa_fila(&f);
    }
    return 0;
}