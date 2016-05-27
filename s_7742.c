#include <stdio.h>

int main(void)
{
        int n, pi, unique;

        scanf("%d", &n);
        scanf("%d", &unique);
        --n;
        while (n--)
        {
                scanf("%d", &pi);
                unique = unique ^ pi;
        }
        printf("%d\n", unique);
        return 0;
}
