#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
        int n, k;
        vector<int> v;
        scanf("%d%d", &n, &k);

        for (int i = 0; i < n; ++i)
        {
                int temp;
                scanf("%d", &temp);
                v.push_back(temp);
        }
        sort(&v[0], &v[n]);
        int i=0, j=1, count=0;
        while(j < n)
        {
                if (v[j] - v[i] == k)
                {
                        ++count;
                        ++i; ++j;
                }
                else if (v[j] - v[i] > k)
                        i++;
                else
                        j++;

        }
        printf("%d\n", count);
        return 0;
}
