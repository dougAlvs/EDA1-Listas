#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) ({Item tt = A; A = B; B = tt;})
#define cmpexch(A, B) ({if(less(B, A)) exch(A, B);})

Item v[200000];

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
    if (r - l == 0) return;
    int m = l + (r - l)/2;
    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    merge(v, l, m , r);
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
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }
    mergesort(v, 0, N - 1);
    int j = 0;
    for (int i = 1; i < N; i++)
    {
        if (v[i] != v[j]) v[++j] = v[i];
    }
    if (j % 2 == 0) v[++j] = 1000000000;
    int novoj = 0;
    for (int i = 0; i < j; i+=2)
    {
        Item temp = v[i] + v[i + 1];
        if (buscabinaria(v, 0, j, temp) == -1 ) v[++novoj + j] = temp;
    }
    merge(v, 0, j, j + novoj + 1);
    j += novoj;
    for (int i = 0; i <= j; i+=4)
    {
        printf("%d\n", v[i]);
    }
    printf("Elementos: %d\n", j + 1);
    free(v);
    return 0;
}
