#include <stdio.h>

long long a[2][1000000];

long long int bin_cof_iter(long long int n, long long int k)
{
     a[0][0] = a[1][0] = 1;
     int i, j, row;
     for (i = 1; i <= n; i++)
     {
          for (j = 1; j <= k; j++)
          {
               if (j == i)
               {
                    a[i%2][j] = 1;
                    break;
               }
               row = (i%2 == 0 ? 1 : 0);
               a[i%2][j] = a[row][j-1] + a[row][j];
          }
     }
     return a[(n)%2][k];
}
long long int bin_cof(long long int n, long long int k)
{
     if(k == 0 || k == n)
          return 1;
     if(k == 1)
          return n;

     return bin_cof(n-1, k-1) + bin_cof(n-1, k);
}


long long marbles(long long n, long long m)
{
     int i;
     long long res=1;
     if (m > n-m)
          m = n - m;
     for (i = 0; i < m; ++i)
          res = res*(n-i) / (i+1);
     return res;
}
int main()
{
     int t;
     long long int n, k, p;

     scanf("%d",&t);

     while(t != 0)
     {
          scanf("%lld%lld", &n, &k);

          printf("%lld\n", marbles(n-1, k-1));
          t--;
     }

     return 0;
}
