#include <stdio.h>

void mover_x(char *str)
{
    if (*str == '\0')
        return;
    else if (*str != 'x')
    {
        printf("%c", *str);
    }
    mover_x(str + 1);
    if (*str == 'x')
    {
        printf("%c", *str);
    }
}

int main(void)
{
    char teste[101];
    scanf("%s", teste);
    mover_x(teste);
    printf("\n");
    return 0;
}