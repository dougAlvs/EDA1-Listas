#include <stdio.h> 
#include <stdlib.h> 

struct valor
{
    int i;
    int n;
};

typedef struct valor item;

#define key(A) (A.n)
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

int buscabinaria (item *v, int l, int r, item b)
{
    if (r < l) return -1;
    int meio = (l + r)/2;
    if (less(b, v[meio])) return buscabinaria(v, l, meio - 1, b);
    else if (less(v[meio], b)) return buscabinaria(v, meio + 1, r, b);
    else return meio;
}

int main (void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    struct valor *v = calloc(N, sizeof(struct valor));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i].n);
        v[i].i = i;
    }
    insertionsort(v, 0, N - 1);
    for (int i = 0; i < M; i++)
    {
        item b;
        scanf("%d", &b.n);
        int pos = buscabinaria(v, 0, N - 1, b);
        if (pos != -1) printf("%d\n", v[pos].i);
        else printf("%d\n", pos);
    }
    free(v);
    return 0;
}