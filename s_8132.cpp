#include <cstdio>
#include <cmath>

int a[100001];

int gcd(int a, int b)
{
    int tmp;

    while (b != 0)
    {
        tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

int main()
{
    int n;
    int f = 1;
    int k;

    scanf("%d", &n);

    scanf("%d", &a[0]);
    scanf("%d", &a[1]);

    k = a[1] - a[0];

    for (int i = 2; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (f)
        {
            k = gcd(a[i] - a[i-1], k);
            if (k == 1)
            {
                f = 0;
            }
        }
    }

    int br = a[n-1] - a[0] + 1;
    int p = ceil((double)br/k);
    int ned = p - n;

    printf("%d\n", ned);

    return 0;
}