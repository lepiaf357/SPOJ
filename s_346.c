#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long max = 0;
//malo elemenata postoji izmedju NIZ_LEN i n/2 n/3 n/4 za brojeve veze od NIZ_LEN
#define NIZ_LEN 10000000
long long niz[NIZ_LEN];
int sss = 0;
long long max_f (long long a, long long b)
{ return a > b ? a : b; }
long long coins_r(long long coin)
{
        long long res;
        if (coin == 0)
                return 0;
        if (coin == 1)
                return 1;
        if (coin < NIZ_LEN)
        {
          if(niz[coin] != -1)
                  return niz[coin];
        }
        else
                ++sss;

        res = max_f (coins_r(coin/2) + coins_r(coin/3) + coins_r(coin/4), coin);
        if (res > max)
                max = res;
        if (coin < NIZ_LEN)
          niz[coin] = res;
        return res;
}

long long coins_recursion(long long coin)
{
        long long res;
        if (coin == 0)
                return 0;
        if (coin == 1)
                return 1;
        res = max_f (coins_recursion(coin/2) + coins_recursion(coin/3) + coins_recursion(coin/4), coin);
        if (res > max)
                max = res;
        return res;
}



int main(void)
{
        long long coin;
        int  n, i;

        while (scanf("%lld", &coin) != EOF)
        {
                if (coin > NIZ_LEN)
                        memset(niz, -1, NIZ_LEN*sizeof(niz[0]));
                else
                        memset(niz, -1, (coin+1)*sizeof(niz[0]));
                max = coin;
                long long a = coins_r (coin);
                printf(" %lld %lld\n", a, max);
                /* coins_r (coin); */
                printf("%lld\n", max);
        }
        return 0;
}
