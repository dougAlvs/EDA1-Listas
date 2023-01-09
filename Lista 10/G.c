#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct drink
{
    int i, n;
    char ch;
};

typedef struct drink Item;

#define key(A) (A.n)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) ({Item tt = A; A = B; B = tt;})
#define cmpexch(A, B) ({if(less(B, A)) exch(A, B);})

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

int main(void)
{
    char *s = calloc(100001 , sizeof(char));
    scanf("%s", s);
    int N = strlen(s);
    Item *v = calloc(N , sizeof(Item));
    int k = 0, l = 0;
    for (int j = 0; j < N; j++)
    {
        if (s[k] != s[j])
        {
            k = j;
            l++;
        }
        v[l].i = k;
        v[l].ch = s[k];
        v[l].n++;
    }
    mergesort(v, 0, l);
    for (int i = l; i >= 0; i--)
    {
        printf("%d %c %d\n", v[i].n, v[i].ch, v[i].i);
    }
    free(s);
    free(v);
    return 0;
}
