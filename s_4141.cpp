#include <cstdio>

using namespace std;

int etf(int t)
{
        int res = t;
        for (int i = 2; i*i <= t; ++i)
        {
                if (t % i == 0)
                        res -= res / i;
                while (t % i == 0)
                        t /= i;
        }
        if (t > 1)
                res -= res / t;
        return res;
}

int main()
{
        int n, t;

        scanf("%d", &n);

        while(n--)
        {
                scanf("%d", &t);

                printf("%d\n", etf(t));
        }
        return 0;
}
