#include <cstdio>
#include <cstring>

using namespace std;

char str[1011];

int failureFun(char *str, int len)
{
        int F[2000], j;

        F[0] = F[1] = 0;
        for (int i = 2; i <= len; ++i)
        {
                j = F[i-1];
                while(1)
                {
                        if (str[j] == str[i-1])
                        { F[i] = j + 1; break; }

                        if (j == 0)
                        { F[i] = 0; break; }
                        j = F[j];
                }
        }
        int res = 0;
        for (int i = 2; i <= len; ++i)
        { res += F[i]; }
        return res;
}

int main()
{
        int n;

        scanf("%d", &n);

        while(n--)
        {
                scanf("%s", str);
                int strLen = strlen(str);
                int prefixSuff = failureFun(str, strLen);

                printf("%d\n", strLen*(strLen+1)/2 - prefixSuff);
        }
        return 0;
}
