#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int n;

    while (1)
    {
        scanf("%d", &n);

        if (n == 0)
            break;

        multiset<long long> s1;
        multiset<long long> s2;

        long long tmp;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &tmp);
            s1.insert(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &tmp);
            s2.insert(tmp);
        }

        long long res = 0;
        multiset<long long>::iterator it1, it2;

        for (it2 = s2.end(), it1 = s1.begin(); it1 != s1.end(); it1++)
        {
            it2--;
            res += *it2 * *it1;
        }
        printf("%lld\n", res);

    }
    return 0;
}
