#include <cstdio>
#include <algorithm>

using namespace std;

int a[101];
int b[10000001];
int c[10000001];

int main()
{
     int n, count, count1;
     scanf("%d", &n);

     for(int i=0; i < n; ++i)
          scanf("%d", &a[i]);

     count = count1 = 0;
     for(int i=0; i < n; ++i)
          for (int j = 0; j < n; ++j)
               for (int k = 0; k < n; ++k, ++count)
               {
                    b[count] = a[i]*a[j]+a[k];
                    if (a[k] != 0)
                         c[count1++] = a[k]*(a[j]+a[i]);
               }
     sort(&b[0], &b[count]);
     sort(&c[0], &c[count1]);

     long long res = 0;
     for(int i=0; i < count; ++i)
     {
          int lo, hi;
          lo = lower_bound(&c[0], &c[count1], b[i]) - c;
          hi = upper_bound(&c[0], &c[count1], b[i]) - c;
          res += hi - lo ;
     }
     printf("%lld\n", res);
     return 0;
}
