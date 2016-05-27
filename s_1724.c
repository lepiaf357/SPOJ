#include <stdio.h>

int main(void)
{
        int n, num;

        scanf("%d", &n);
        while(n--)
        {
                scanf("%d", &num);
                if (num & 1)//odd
                        printf("%lld\n", ((long long)num * (num + 2) * (2*num + 1)-1) / 8);
                else //even
                        printf("%lld\n", (long long)num * (num + 2) * (2*num + 1) / 8);

        }
        return 0;
}
