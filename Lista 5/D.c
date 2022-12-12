#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cont = 0;

char* substr(char *str, int inicio, int fim)
{
    int len = fim - inicio;
    char *temp = malloc(1 * (len + 1));
    strncpy(temp, (str + inicio), len);
    return temp;
}

int maiorSub(char *str, char *sub)
{
    if (strlen(str) < strlen(sub)) return 0;
    else if (strlen(str) == strlen(sub))
    {
       return strcmp(str, sub) ? 0 : strlen(str);
    }
    else
    {
        int len = strlen(sub);
        char *primeiro = substr(str, 0, len);
        char *ultimo = substr(str, strlen(str) - len, strlen(str));
        if (strcmp(primeiro, sub) == 0 && strcmp(ultimo, sub) == 0)
        {
            return strlen(str);
        }
        else if (strcmp(primeiro, sub) == 0 && strcmp(ultimo, sub) != 0)
        {
            return maiorSub(substr(str, 0, strlen(str) - 1), sub);
        }
        else if (strcmp(primeiro, sub) != 0 && strcmp(ultimo, sub) == 0)
        {
            return maiorSub(substr(str, 1, strlen(str)), sub);
        }
        else
        {
            return maiorSub(substr(str, 1, strlen(str) - 1), sub);
        }
        
    }
    
}

int main(void)
{
    char str[101];
    char sub[101];
    scanf("%s %s", str, sub);
    printf("%d\n", maiorSub(str, sub));
    return 0;
}

// #include <stdio.h>
// #include <string.h>

// int contador = 0;
// int cont = 0;
// char *inicial_sub;

// int sub(char *string, char *substring){
//     if(*string == '\0'){
//         if(contador > strlen(inicial_sub)){return (contador + cont);}
//         else{return contador;}
//     }

//     if(*string == *substring){
//         contador++;
//         return sub(string + 1, substring + 1);
//     } else if(contador < strlen(substring)){
//         contador = 0;
//         return sub(string + 1, inicial_sub);
//     } else if(contador == strlen(inicial_sub)){
//         if(*string == *inicial_sub){
//             return sub(string, inicial_sub);
//         } else{
//             cont++;
//             return sub(string + 1, inicial_sub);
//         }
//     } else if(contador == (2 * strlen(inicial_sub))){
//         return sub(string + 1, substring);
//     } else{
//         int rest = contador - strlen(inicial_sub);
//         contador = contador - rest;
//         cont = cont + rest;
//         return sub(string, inicial_sub);
//     }
// }

// int main (){
//     char string[101], substring[101];
//     scanf("%s", string);
//     scanf("%s", substring);

//     inicial_sub = substring;

//     printf("%d\n", sub(string, substring));
// }