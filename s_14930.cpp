#include <cstdio>
#include <algorithm>

using namespace std;

int a[10000];
long long t[10002];

long long farida_r(int n, int i)
{
     if (i >= n)
          return 0;

     return max(farida_r(n, i+1), farida_r(n, i+2) + a[i]);
}

long long farida(int n)
{
     t[n] = 0;
     t[n+1] = 0;

     for (int i = n-1; i >= 0; i--)
          t[i] = max(t[i+1], t[i+2] + a[i]);

     return t[0];
}
int main()
{
     int t, n;
     scanf("%d", &t);
     int j = 0;

     while (t--)
     {
          scanf("%d", &n);
          for (int i = 0; i < n; i++)
               scanf("%d", &a[i]);

          j++;
          printf("Case %d: %lld\n", j, farida(n));

     }

     return 0;
}
