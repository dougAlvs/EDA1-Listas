#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dicio 
{
    char jap[81];
    char bra[81];
};

typedef struct dicio Item;

#define key(A) (A.jap)
#define less(A,B) (strcmp(key(A), key(B)) < 0)
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
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        Item *dicionario = malloc(m * sizeof(Item)); 
        for (int i = 0; i < m; i++)
        {
            scanf(" %[^\n]", dicionario[i].jap);
            scanf(" %[^\n]", dicionario[i].bra);
        }
        quicksort(dicionario, 0, m - 1);
        for (int i = 0; i < n; i++)
        {
            char mus[81];
            scanf(" %[^\n]s", mus);
            char *palavra = strtok(mus, " ");
            while (palavra != NULL)
            {   
                Item temp;
                strcpy(temp.jap, palavra);
                int j = buscabinaria(dicionario, 0, m - 1, temp);
                printf("%s ", j != -1 ? dicionario[j].bra : temp.jap);
                palavra = strtok(NULL, " ");
            }
            printf("\n");
        }
        printf("\n");
        free(dicionario);
    }
    return 0;
}