#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// int failureFun(char *str, int len)
// {
//         int F[2000], j;

//         F[0] = F[1] = 0;
//         for (int i = 2; i <= len; ++i)
//         {
//                 j = F[i-1];
//                 while(1)
//                 {
//                         if (str[j] == str[i-1])
//                         { F[i] = j + 1; break; }

//                         if (j == 0)
//                         { F[i] = 0; break; }
//                         j = F[j];
//                 }
//         }
//         int res = 0;
//         for (int i = 2; i <= len; ++i)
//         { res += F[i]; }
//         return res;
// }
char str[1001];


struct arrElement
{
        int pos;
        char *s;
};

arrElement suff[1001];

int cmp(arrElement a, arrElement b)
{ return strcmp(a.s, b.s) < 0 ? 1 : 0; }

int suffixArr(int len)
{
        for (int i = 0; i < len; ++i)
        {
                suff[i].s = (&str[0] + i);
                suff[i].pos = i;
        }
        // for (int i = 0; i < len; ++i)
        //         printf("%s\n", suff[i].s);
        sort(&suff[0], &suff[len], cmp);
        // for (int i = 0; i < len; ++i)
        //         printf("%s\n", suff[i].s);

        int sum = 0, i = 0;
        sum += len - suff[0].pos;
        while(i < len-1)
        {
                int j;
                // printf("sum: %d\n", sum);
                for (j = 0; j < len - suff[i].pos && j < len - suff[i+1].pos; ++j)
                {
                        // printf("%c %c\n", suff[i].s[j], suff[i+1].s[j]);
                        if (suff[i].s[j] != suff[i+1].s[j])
                                break;
                }
                // printf("j %d\n", j);
                sum += len - suff[i+1].pos - j;
                ++i;
        }
        return sum;
}

int main()
{
        int n;

        scanf("%d", &n);

        while(n--)
        {
                scanf("%s", str);
                int strLen = strlen(str);
                printf("%d\n", suffixArr(strLen));
                // printf("%d\n", strLen*(strLen+1)/2 - prefixSuff);
        }
        return 0;
}
