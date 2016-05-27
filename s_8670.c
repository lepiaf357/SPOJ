#include <stdio.h>

int main(void)
{
        int n, i;
        float r;

        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
        {
                scanf("%f", &r);
                printf("Case %d: %.2f\n", i, 4 * r * r + 1./4);
        }
        return 0;
}
