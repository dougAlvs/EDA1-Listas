#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))

void merge(Item *v, int l, int m, int r)
{
    Item *aux = malloc(sizeof(Item) * (r - l + 1));
    int iv1 = l, iv2 = m + 1, iaux = 0;

    while (iv1 <= m && iv2 <= r)
    {
        if(less(v[iv1], v[iv2])) aux[iaux++] = v[iv1++];
        else aux[iaux++] = v[iv2++];
    }
    
    while (iv1 <= m)
    {
        aux[iaux++] = v[iv1++];
    }
    
    while (iv2 <= r)
    {
        aux[iaux++] = v[iv2++];
    }
    
    for (int i = 0; i < iaux; i++)
    {
        v[l++] = aux[i];
    }
    free(aux);
}

void mergesort(Item *v, int l, int r)
{
    if(r - l == 0) return;
    int meio = l + (r - l)/2;
    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int buscabinaria(Item *v, int l, int r, Item b)
{
    if(r < l) return - 1;
    int meio = l + (r - l)/2;
    if (less(b, v[meio])) buscabinaria(v, l, meio - 1, b);
    else if (less(v[meio], b)) buscabinaria(v, meio + 1, r, b);
    else return meio;
}


int main(void)
{
    int N;
    Item b;

    scanf("%d", &N);
    Item *v = malloc(sizeof(Item) * N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, N - 1);

    while ((scanf("%d", &b)) == 1)
    {
        printf(buscabinaria(v, 0, N - 1, b) == -1 ? "nao\n" : "sim\n");
    }
    return 0;
}