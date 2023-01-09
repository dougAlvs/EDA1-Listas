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
        if (less(v[iv1], v[iv2])) aux[iaux++] = v[iv1++];
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
    if (l >= r) return;
    int meio = l + ((r - l)/2);
    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    Item *v = malloc(sizeof(Item) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        printf(i == N - 1 ? "%d\n" : "%d ", v[i]);
    }
    
    return 0;
}