#include <stdio.h>
#include <stdlib.h>

struct candidato
{
    int cod, qtd;
};

typedef struct candidato Item;

#define key(A) (A.qtd)
#define less(A,B) (key(A) == key(B) ? A.cod > B.cod : key(A) > key(B))
#define exch(A, B) ({Item tt = A; A = B; B = tt;})
#define cmpexch(A, B) ({if(less(B, A)) exch(A, B);})

Item pres[99];
Item sen[999];
Item depFed[9999];
Item depEst[99999];

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
    long long int S, F, E;
    scanf("%lld %lld %lld", &S, &F, &E);
    int voto, tam;
    long long int validos = 0, invalidos = 0, tp = 0, ip = 0, is = 0, idf = 0, ide = 0;
    while (scanf("%d%n", &voto, &tam) == 1)
    {
        if (voto < 0)
        {
            invalidos++;
            continue;
        }
        if (tam == 3)
        {
            pres[voto].cod = voto;
            pres[voto].qtd++;
            tp++;
        }
        else if (tam == 4)
        {
            sen[voto].cod = voto;
            sen[voto].qtd++;
        }
        else if (tam == 5)
        {
            depFed[voto].cod = voto;
            depFed[voto].qtd++;
        }
        else if (tam == 6)
        {
            depEst[voto].cod = voto;
            depEst[voto].qtd++;
        }
        validos++;
    }

    for (int i = 0; i < 99; i++)
    {
        if (pres[i].qtd)
            pres[ip++] = pres[i];
    }
    
    for (int i = 0; i < 999; i++)
    {
        if (sen[i].qtd)
            sen[is++] = sen[i];
    }
    
    for (int i = 0; i < 9999; i++)
    {
        if (depFed[i].qtd)
            depFed[idf++] = depFed[i];
    }

    for (int i = 0; i < 99999; i++)
    {
        if (depEst[i].qtd)
            depEst[ide++] = depEst[i];
    }

    quicksort(pres, 0, ip - 1);
    quicksort(sen, 0, is - 1);
    quicksort(depFed, 0, idf - 1);
    quicksort(depEst, 0, ide - 1);

    printf("%lld %lld\n", validos, invalidos);

    if ((double) pres[0].qtd / tp >= 0.51) 
            printf("%d\n", pres[0].cod);
    else   
        printf("Segundo Turno\n");

    for (int i = 0; i < S; i++)
    {
        printf(i != S - 1 ? "%d " : "%d\n", sen[i].cod);
    }
    
    for (int i = 0; i < F; i++)
    {
        printf(i != F - 1 ? "%d " : "%d\n", depFed[i].cod);
    }
    for (int i = 0; i < E; i++)
    {
        printf(i != E - 1 ? "%d " : "%d\n", depEst[i].cod);
    }
    
    return 0;
}