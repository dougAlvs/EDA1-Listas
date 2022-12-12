#include <stdio.h>

int main (void) {
    int n;
    int total = 0;
    scanf("%d",&n);
    for (int i = 0;i<n;i++) {
        int x;
        scanf("%d",&x);
        total += x;
    }
    printf("%d",total);

    return 0;
}