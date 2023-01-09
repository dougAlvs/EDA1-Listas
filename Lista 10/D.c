#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))

int buscabinaria(Item *v, int l, int r, Item b)
{
    int meio = l + (r - l)/2;
    if ((less(b, v[meio]) && meio == l) || b == v[meio]) return meio;
    if ((less(v[meio], b) && meio == r)) return meio + 1;
    if (less(b, v[meio])) buscabinaria(v, l, meio - 1, b);
    else if (less(v[meio], b)) buscabinaria(v, meio + 1, r, b);
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    Item *v = malloc(sizeof(Item) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < M; i++)
    {
        Item b;
        scanf("%d", &b);
        printf("%d\n", buscabinaria(v, 0, N - 1, b));
    }
    free(v);
    return 0;
}