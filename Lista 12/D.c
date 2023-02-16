#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct pilha_st
{
    Item *v;
    int size,
        topo;
} pilha;

int inicializa_pilha(pilha *p, int s)
{
    p -> v = malloc(s * sizeof(Item));
    if (p -> v == NULL) return 0;
    p -> size = s;
    p -> topo = 0;
    return 1;
}

int empilha(pilha *p, Item e)
{
    if (p ->topo == p -> size) return 0;
    p ->v[p -> topo++] = e;
    return 1;
}

int p_vazia(pilha *p)
{
    return p -> topo == 0;
}

Item topo(pilha *p)
{
    return p -> v[p ->topo - 1];
}

void desempilha(pilha *p)
{
    p -> topo--;
}

void limpa_pilha(pilha *p)
{
    free(p -> v);
    p -> size = 0;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        Item *A = malloc(sizeof(Item) * 100000);
        scanf(" %s", A);
        int j = 0;
        pilha p;
        inicializa_pilha(&p, 100000);
        while (A[j] != '\0')
        {
            if (A[j] == '(' || A[j] == '[' || A[j] == '{')
            {
                empilha(&p, A[j]);
            }
            Item top = topo(&p);
            if ((A[j] == ')' && top == '(') || (A[j] == ']' && top == '[') || (A[j] == '}' && top == '{'))
            {
                desempilha(&p);
            }
            if ((A[j] == ')' && top != '(') || (A[j] == ']' && top != '[') || (A[j] == '}' && top != '{'))
            {
                empilha(&p, A[j]);
            }
            j++;
        }
        printf(p_vazia(&p) ? "S\n" : "N\n"); 
        limpa_pilha(&p);  
        free(A);
    }
    return 0; 
}   
