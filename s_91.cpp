#include <cstdio>
#include <cmath>

void two_squares(long long n)
{
    int  c = 0;
    for(int i = 2; i*i <= n; i++)
    {
        int j = 0;
        while(n % i == 0)
        {
            j++;
            n=n/i;
        }

        if(i % 4 == 3 && j % 2 != 0)
        {
            c = 1;
            break;
        }
    }

    if (n % 4 == 3)
        c = 1;

    if (c == 0)
        printf("Yes\n");
    else
        printf("No\n");
}


int main()
{
    int t;
    long long n;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%lld", &n);

        long long a = sqrt(n);

        if (a*a == n)
           printf("Yes\n");
        else
           two_squares(n);
    }

    return 0;
}
