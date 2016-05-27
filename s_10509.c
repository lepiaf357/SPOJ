#include <stdio.h>

int main()
{
        int n, t;

        scanf("%d", &n);

        while(n--)
        {
                scanf("%d", &t);
                long long res = ((long long)t * ( 3 * t + 1)) / 2 ;
                printf("%d\n", (int)(res % 1000007));
        }
        return 0;
}
