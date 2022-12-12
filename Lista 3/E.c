#include <stdio.h>
long long int f[81] = {[0 ... 80] = -1};
long long int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    
    if (f[n] != -1)
    {
        return f[n];
    }
    f[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return f[n];
}