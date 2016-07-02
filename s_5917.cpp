#include <cstdio>
#include <cmath>

int main()
{
     int t;
     long long n;

     scanf("%d", &t);

     while (t--)
     {
         scanf("%lld", &n);
         if (n == 0 || n == 1)
              printf("1\n");
         else
         {
             long long ans = (log(2.0*M_PI*n)/2 + n*(log((double)n) - log(M_E)))/log(10.0);
             long long b = floor(ans) + 1;
             printf("%lld\n", b);
         }
     }
     return 0;
}
