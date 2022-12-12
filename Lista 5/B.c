#include <stdio.h>

void trocarX(char str[81])
{
    if (*str == '\0') return;
    if (*str == 'x') printf("y");
    else printf("%c", *str);     
    trocarX(str + 1);
}


int main(void) 
{
    char str[81];
    scanf("%s", str);
    trocarX(str);

    return 0;
}