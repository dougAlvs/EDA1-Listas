#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))


Item* merge2(Item *v1, Item *v2, int l1, int r1, int l2, int r2)
{
    Item *v3 = malloc(sizeof(Item) * ((r1 - l1 + 1)+(r2 - l2 + 1)));
    int iv1 = l1, iv2 = l2, iv3 = 0;
    while (iv1 <= r1 && iv2 <= r2)
    {
        if (less(v2[iv2], v1[iv1])) v3[iv3++] = v2[iv2++];
        else v3[iv3++] = v1[iv1++];
    }

    while (iv1 <= r1)
    {
        v3[iv3++] = v1[iv1++];
    }

    while (iv2 <= r2)
    {
        v3[iv3++] = v2[iv2++];
    }
    
    return v3;
}

Item* merge4(Item *v1, Item *v2, Item *v3, Item *v4, int l1, int r1, int l2, int r2, int l3, int r3, int l4, int r4)
{
    Item *v7 = malloc(sizeof(Item) * ((r1 - l1 + 1)+(r2 - l2 + 1) + (r3 - l3 + 1)+(r4 - l4 + 1)));
    Item *v5 = merge2(v1, v2, l1, r1, l2, r2);
    Item *v6 = merge2(v3, v4, l3, r3, l4, r4);
    v7 = merge2(v5, v6, 0, r1 - l1 + r2 - l2 + 1, 0, r3 - l3 + r4 - l4 + 1);
    free(v5);
    free(v6);
    return v7;
}

Item* merge8(Item *v1, Item *v2, Item *v3, Item *v4, Item *v5, Item *v6, Item *v7, Item *v8, int l1, int r1, int l2, int r2, int l3, int r3, int l4, int r4, int l5, int r5, int l6, int r6, int l7, int r7, int l8, int r8)
{
    Item *v11 = malloc(sizeof(Item) * ((r1 - l1 + 1)+(r2 - l2 + 1) + (r3 - l3 + 1)+(r4 - l4 + 1) + (r5 - l5 + 1)+(r6 - l6 + 1) + (r7 - l7 + 1)+(r8 - l8 + 1)));
    Item *v9 = merge4(v1, v2, v3, v4, l1, r1, l2, r2, l3, r3, l4, r4);
    Item *v10 = merge4(v5, v6, v7, v8, l5, r5, l6, r6, l7, r7, l8, r8);
    v11 = merge2(v9, v10, 0, r1 - l1 + r2 - l2 + r3 - l3 + r4 - l4 + 3, 0, r5 - l5 + r6 - l6 + r7 - l7 + r8 - l8 + 3);
    free(v9);
    free(v10);
    return v11;
}


int main(void)
{
        int S1;
        scanf("%d", &S1);
        Item *v1 = malloc(S1 * sizeof(Item));
        for (int i = 0; i < S1; i++)
        {
            scanf("%d", v1 + i);
        }

        int S2;
        scanf("%d", &S2);
        Item *v2 = malloc(S2 * sizeof(Item));
        for (int i = 0; i < S2; i++)
        {
            scanf("%d", v2 + i);
        }

        int S3;
        scanf("%d", &S3);
        Item *v3 = malloc(S3 * sizeof(Item));
        for (int i = 0; i < S3; i++)
        {
            scanf("%d", v3 + i);
        }

        int S4;
        scanf("%d", &S4);
        Item *v4 = malloc(S4 * sizeof(Item));
        for (int i = 0; i < S4; i++)
        {
            scanf("%d", v4 + i);
        }

        int S5;
        scanf("%d", &S5);
        Item *v5 = malloc(S5 * sizeof(Item));
        for (int i = 0; i < S5; i++)
        {
            scanf("%d", v5 + i);
        }
    
        int S6;
        scanf("%d", &S6);
        Item *v6 = malloc(S6 * sizeof(Item));
        for (int i = 0; i < S6; i++)
        {
            scanf("%d", v6 + i);
        }

        int S7;
        scanf("%d", &S7);
        Item *v7 = malloc(S7 * sizeof(Item));
        for (int i = 0; i < S7; i++)
        {
            scanf("%d", v7 + i);
        }

        int S8;
        scanf("%d", &S8);
        Item *v8 = malloc(S8 * sizeof(Item));
        for (int i = 0; i < S8; i++)
        {
            scanf("%d", v8 + i);
        }

        Item *v9 = merge8(v1, v2, v3, v4, v5, v6, v7, v8, 0, S1 - 1, 0, S2 - 1, 0, S3 - 1, 0, S4 - 1, 0, S5 - 1, 0, S6 - 1, 0, S7 - 1, 0, S8 - 1);

        int tamv9 = S1 + S2 + S3 + S4 + S5 + S6 + S7 + S8;
        for (int i = 0; i < tamv9; i++)
        {
            printf("%d ", v9[i]);
        }      
        free(v1);
        free(v2);
        free(v3);
        free(v4);
        free(v5);
        free(v6);
        free(v7);
        free(v8);
        free(v9);
        return 0;
}