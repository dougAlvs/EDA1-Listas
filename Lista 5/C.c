#include <stdio.h>

void gnirts (char str[501])
{
    if (*str == '\0') return;
    gnirts(str + 1);
    printf("%c", *str);

}

int main(void)
{
    char str[501];
    scanf("%s", str);
    gnirts(str);
    printf("\n");
    return 0;
}