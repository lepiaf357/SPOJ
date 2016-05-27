#include <stdio.h>

int coin_recursive(int *a, int n, int i)
{
        int x = 0, y = 0;
        if (i == n-1 || i == n)
                return 1;
        if (a[i] <= 1 || (a[i] == 2 && a[i+1] <= 6))
                x = coin_recursive(a, n, i+2);
        if (a[i] != 0)
                y = coin_recursive(a, n, i+1);
        return x + y;
}

long long coin_iterative(int *a, int n)
{
        long long table[5000];
        int i, j;

        if (a[n-1] == 0)
                table[n-1] = 0;
        else
                table[n-1] = 1;
        if (a[n-2] != 0)
                table[n-2] = table[n-1] + 1;

        for (i = n-3; i >= 0; --i)
        {
                int x = 0;
                if (a[i] <= 1 || (a[i] == 2 && a[i+1] <= 6))
                        x = table[i+1] + 1;
                if (a[i] != 0)
                        if (x != 0)
                                ++x;
                        else
                                x = table[i+1] + 1;
                table[i] = x;
        }
        return table[0];

}
int main(void)
{
        int number[5000], i, j, n;
        char c;

        while(1)
        {
                scanf("%c", &c);
                n = 0;
                if (c == '0')
                        break;
                i = 0;
                do
                {
                        number[i++] = c - '0';
                        ++n;
                        scanf("%c", &c);
                } while(c >= '0' && c <= '9') ;
                /* printf("%d\n", coin_recursive(&number[0], n, 0)); */
                printf("%lld\n", coin_iterative(&number[0], n));

        }

        return 0;
}
