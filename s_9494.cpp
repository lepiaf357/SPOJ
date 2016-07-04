#include <cstdio>

int int_mod(int a, int b)
{
    return (a % b + b) % b; 
}

long long power(long long a, long long b)
{
    long long ret = 1;

    while(b > 0)
    {
        if(b % 2 != 0)
            ret = (ret * a) % 10000007;

        a = (a * a) % 10000007;
        b /= 2;

    }
    return ret;
}

int main()
{
    long long n, k;

    while (1)
    {
        scanf("%lld%lld", &n, &k);

        if (n == 0 && k == 0)
            break;


        long long p1, p2, p1_1, p2_1;

        p1 = power(n, n);
        p1_1 = (2 * power(n-1, n-1)) % 10000007;
        p2 = power(n, k);
        p2_1 = (2 * power(n-1, k)) % 10000007;

        long long sum = (p1 + p1_1 + p2_1 + p2) % 10000007;

        printf("%lld\n", sum);
    }

    return 0;
}