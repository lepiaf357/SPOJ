#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

void print_num(long long n, int a)
{
    vector<int> v;
    vector<int>::iterator it;

    while (n != 0)
    {
       if (n % 2 == 0)
           v.push_back(5);
       else
           v.push_back(6);
       n /= 2;
    }

    int s = a - v.size();

    while (s > 0)
    {
        printf("5");
        s--;
    }
    if (v.size() != 0)
    {
        for (it = v.end() - 1; it >= v.begin(); it-- )
            printf("%d", *it);
    }
    printf("\n");
}

int main()
{
    int t;
    long long k;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%lld", &k);

        if (k == 1)
            printf("5\n");
        else
        {
            int a = floor(log2(k+1));
            //printf("%d\n", a);

            long long n = k + 1 - pow(2, a);
            //printf("%lld\n", n);

            print_num(n, a);
        }
    }
    return 0;
}