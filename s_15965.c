#include <stdio.h>

long long nzd(long long a, long long b)
{
     long long tmp;

     while (b != 0)
     {
          tmp = b;
          b = a % b;
                         a = tmp;
     }

     return a;
}
int main()
{
     int t;
     long long a, b;
     scanf("%d", &t);
     while (t != 0)
     {
          scanf("%lld%lld", &a, &b);
          printf("%lld %lld\n", b / nzd(a, b), a / nzd(a, b));
          t--;
     }
     return 0;
}
