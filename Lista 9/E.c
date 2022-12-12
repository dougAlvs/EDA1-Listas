#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct instrucao
{
    int codigo;
    char palavra[16];
};

typedef struct instrucao item;

#define key(A) (A.codigo)
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
    int N;
    scanf("%d", &N);
    struct instrucao *v = calloc(N, sizeof(struct instrucao));
    for (int i = 0; i < N; i++)
    {
        char palavra_chave[16]; 
        scanf("%d %s", &v[i].codigo, &palavra_chave);
        strcpy(v[i].palavra, palavra_chave);
    }
    insertionsort(v, 0, N - 1);
    item cmd;
    while (scanf("%d", &cmd.codigo) == 1)
    {
        int pos = buscabinaria(v, 0, N - 1, cmd);
        if (pos != -1) printf("%s\n", v[pos].palavra);
        else printf("undefined\n");
    }
    free(v);
    return 0;
}