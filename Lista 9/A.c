#include <stdio.h> 
#include <stdlib.h> 

typedef int item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A,B) {item tt = A; A = B; B = tt;}

void bubblesort(item *v, int l, int r)
{
    for (int i = l; i < r; i++)
    {
        for (int j = l; j < r; j++)
        {
            if (less(v[j + 1], v[j])) exch (v[j + 1], v[j])
        }
    }   
}

int main (void)
{
    int *v = calloc(1000, 4);
    int j = 0;
    while (scanf("%d", &v[j]) == 1) j++;
    bubblesort(v, 0, j - 1);
    for (int i = 0; i < j; i++)
    {
        if (i == j - 1) printf("%d\n",v[i]);
        else printf("%d ",v[i]);
    }
    free(v);
    return 0;
}