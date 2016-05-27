#include <stdio.h>

int main()
{
        long long sum, n, a3, an_2, d, a;
        int k, i;

        scanf("%d", &k);

        while (k--)
        {
                scanf("%lld%lld%lld", &a3, &an_2, &sum);

                n = 2 * sum / (a3 + an_2);

                d = (an_2 - a3) / (n - 5);

                printf("%lld\n", n);
                a = a3 - 2*d;
                for (i = 1; i <= n; ++i)
                        printf("%lld ", a + (i-1)*d);
                printf("\n");
        }
        return 0;
}
