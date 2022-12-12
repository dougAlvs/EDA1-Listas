#include <stdio.h> 
#include <stdlib.h> 

typedef int item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A,B) {item tt = A; A = B; B = tt;}
#define cmpexch(A,B) {if less(B, A) exch (A, B);}

void insertionsort(item *v, int l, int r)
{
    for (int i = r; i > l; i--)
    {
        cmpexch(v[i - 1], v[i]);
    }
    for (int i = l + 2; i <= r; i++)
    {
        item mao = v[i];
        int j = i;
        while (less(mao, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = mao;
    }    
}

int main (void)
{
    int *v = calloc(50000, 4);
    int j = 0;
    while (scanf("%d", &v[j]) == 1) j++;
    insertionsort(v, 0, j - 1);
    for (int i = 0; i < j; i++)
    {
        if (i == j - 1) printf("%d\n",v[i]);
        else printf("%d ",v[i]);
    }
    free(v);
    return 0;
}