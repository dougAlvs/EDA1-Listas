#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define exch(A, B) ({Item tt = A; A = B; B = tt;})
#define cmpexch(A, B) ({if(less(B, A)) exch(A, B);})

int partition(Item *v, int l, int r)
{
    Item p = v[r];
    int i = l - 1, j = r;
    for(;;)
    {
        while (less(v[++i], p));
        while (less(p, v[--j])) if (j == l) break;
        if (j <= i) break;
        exch(v[j], v[i]);
    }
    exch(v[i], v[r]);
    return i;
}

void insertionsort(Item *v, int l, int r)
{
    for (int i = r; i > l; i--)
    {
        cmpexch(v[i - 1], v[i]);
    }
    for (int i = l + 2; i <= r; i++)
    {
        Item mao = v[i];
        int j = i;
        while (less(mao, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = mao;
    }    
}

void quicksortM3(Item *v, int l, int r)
{
    if (r - l + 1 <= 16) return;
    exch(v[(l+r)/2], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[r - 1], v[r]);
    int j = partition(v, l + 1, r - 1);
    quicksortM3(v, l, j - 1);
    quicksortM3(v, j + 1, r);
}

void quicksort(Item *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    Item *v = calloc(n, sizeof(Item));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    quicksort(v, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf(i != n - 1 ? "%d " : "%d\n", v[i]);
    }
    free(v);
    return 0;
}