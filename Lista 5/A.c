#include <stdio.h>

int n = 0;

int nPares(char str[201])
{
    if (*str == '\0') return 0;
    if (*str == *(str + 2))
    {
        n++;
    }
    nPares(str + 1);
    return n;   

}


int main(void) 
{
    char str[201];
    scanf("%s", str);
    printf("%d\n", nPares(str));
    return 0;
}