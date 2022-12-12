#include <stdio.h>

int main(void) {  
    int R, contador = 1;
    while (scanf("%d",&R) == 1) {
        int vetor[2 * R];
        for (int i = 0;i < 2 * R;i++) {
            scanf("%d", &vetor[i]);
        }
        int maior = vetor[1];
        int codigoMaior = vetor[0];
        for(int i = 0;i < (2 * R);i++) {
            if (i%2 != 0 && vetor[i] > maior) {
                maior = vetor[i];
                codigoMaior = vetor[i-1];
                continue;
            }
            if (i%2 != 0 && vetor[i] == maior) {
                if (vetor[i-1] < codigoMaior) {
                    codigoMaior = vetor[i - 1];
                }
            }
        }
        printf("Dia %d\n%d\n\n", contador, codigoMaior);
        contador++;
    }

    return 0;
}