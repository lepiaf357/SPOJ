#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;
int mixtures[101];


int color(int l, int r)
{
        int res = 0;
        for (; l <= r; ++l)
                res = res + mixtures[l] % 100;
        return res;
}

int harry_r(int l, int r)
{
        int minimum = INT_MAX;
        if (l == r)
                return 0;
        for (int i = l; i < r; i++)
        {
                int a = harry_r(l, i) + harry_r(i+1, r) + color(l, i)*color(i+1, r);
                if (minimum > a)
                        minimum = min(a, minimum);
        }
        return minimum;

}

int main()
{
        int n;
        while (scanf("%d", &n) > 0)
        {
                for (int i = 0; i< n; i++)
                {
                        scanf("%d", &mixtures[i]);
                }
                printf("%d\n", harry_r(0, n-1));
        }


}
