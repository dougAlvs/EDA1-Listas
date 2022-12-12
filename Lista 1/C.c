#include <stdio.h>

int main (void) {
    int N;
    do {
        scanf("%d",&N);
        int R[N];
        for (int i=0;i<N;i++) {
            scanf("%d",&R[i]);
        }
    int alice = 0, beto = 0;
    for(int i=0;i<sizeof(R)/sizeof(R[0]);) {
        if (R[i] == 0) {
            alice++;
        }
        else {
            beto++;
        }
    }      
    printf("Alice ganhou %d e Beto ganhou %d\n", alice, beto);

    } while (N != 0);
    return 0;
}