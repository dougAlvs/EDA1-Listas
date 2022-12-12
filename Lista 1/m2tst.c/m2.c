#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int L, Cl, Cc;
    char cmd;
    scanf("%d", &L);
    char **texto = calloc(L, 1);
    getchar();
    for (int i = 0; i < L; i++)
    {
        texto[i] = calloc(1001, sizeof(char));
        fgets(texto[i], 1001, stdin);
    }
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < strlen(texto[i]); j++)
        {
            if (texto[i][j] == '\n')
            {
                texto[i][j] = '\0';
            }
        }
    }
    
    scanf("%d %d", &Cl, &Cc);
    // printf("Posicao Inicial: %c\n", texto[Cl - 1][Cc - 1]);
    int posl = Cl, posc = Cc;
    while (scanf("%c", &cmd) == 1)
    {
        // printf("PosL: %d PosC: %d\n", posl, posc);
        if (cmd == 'k' && posl == 1)
        {
            // printf("If linha 27\n");
            if (cmd == 'k' && (texto[posl - 1][posc - 1] ==  '\0' && (texto[posl - 1][posc] ==  '\0')))
            {
                // printf("If linha 30\n");
                char chartemp = texto[posl - 1][posc - 1];
                int cont = 1;
                while (1)
                {
                    // printf("While linha 35 n: %d\n", cont);
                    if (chartemp !=  '\0' && chartemp != '\n')
                    {
                        // printf("If linha 37\n");
                        break;
                    }
                    cont++;
                    chartemp = texto[posl - 1][posc - cont];
                }
                printf("%d %d %c\n", posl, posc - cont + 1, chartemp);

                continue;
            }
            else
            {
                // printf("If linha 48\n");
                printf("%d %d %c", posl, posc, texto[posl - 1][posc - 1]);
                continue;
            }
        }
        else if (cmd == 'j' && posl == L)
        {
            // printf("If linha 55\n");
            if (texto[posl - 1][posc - 1] ==  '\0' && texto[posl - 1][posc] ==  '\0')
            {
                // printf("If linha 58\n");
                char chartemp = texto[posl - 1][posc - 1];
                int cont = 1;
                while (1)
                {
                    // printf("While linha 63 n: %d\n", cont);
                    if (chartemp !=  '\0')
                    {
                        // printf("If linha 65\n");
                        break;
                    }
                    cont++;
                    chartemp = texto[posl - 1][posc - cont];
                }
                printf("%d %d %c\n", posl, posc - cont + 1, chartemp);
                continue;
            }
            else
            {
                // printf("If linha 76\n");
                printf("%d %d %c\n", posl, posc, texto[posl - 1][posc - 1]);
                continue;
            }
        }
        else if (cmd == 'j' && (((texto[posl][posc - 1]) || (texto[posl][posc])) != '\0'))
        {
            // printf("If linha 85\n");
            posl += 1;
            printf("%d %d %c\n", posl, posc, texto[posl - 1][posc - 1]);
            continue;
        }
        else if (cmd == 'k' && ((texto[posl - 2][posc - 1] || texto[posl - 2][posc]) !=  '\0'))
        {
            // printf("If linha 90\n");
            posl -= 1;
            printf("%d %d %c\n", posl, posc, texto[posl - 1][posc - 1]);
            continue;
        }
        else if (cmd == 'k' && (texto[posl - 2][posc - 1] ==  '\0' && texto[posl - 2][posc] ==  '\0'))
        {
            // printf("If linha 97\n");
            posl -= 1;
            char chartemp = texto[posl - 1][posc - 1];
            int cont = 1;
            while (1)
            {
                // printf("While linha 103 n: %d\n", cont);
                if (chartemp !=  '\0')
                {
                    // printf("If linha 105\n");
                    break;
                }
                cont++;
                chartemp = texto[posl - 1][posc - cont];
            }
            printf("%d %d %c\n", posl, posc - cont + 1, chartemp);
            continue;
        }
        else if (cmd == 'j' && ((texto[posl][posc - 1] ==  '\0' && texto[posl][posc] ==  '\0')))
        {
            // printf("If linha 116\n");
            posl += 1;
            char chartemp = texto[posl - 1][posc - 1];
            int cont = 1;
            while (1)
            {
                // printf("While linha 122 n: %d\n", cont);
                if (chartemp !=  '\0')
                {
                    // printf("If linha 125\n");
                    break;
                }
                cont++;
                chartemp = texto[posl - 1][posc - cont];
            }
            printf("%d %d %c\n", posl, posc - cont + 1, chartemp);
            continue;
        }
    }
    free(texto);
    return 0;
}