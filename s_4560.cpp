#include <cstdio>
#include <algorithm>

using namespace std;

int a[10000];
int b[10000];

int main()
{
     int n, m;

     while(1)
     {
          scanf("%d", &n);
          if (n == 0)
               break;
          for (int i = 0; i < n; ++i)
               scanf("%d", &a[i]);

          scanf("%d", &m);
          for (int i = 0; i < m; ++i)
               scanf("%d", &b[i]);
          int i = 0, j = 0, sum = 0, sum_a = 0, sum_b =0;
          for (;i < n && j < m;)
          {
               if (a[i] < b[j])
               {
                    sum_a += a[i];
                    ++i;
                    // a[i] += a[i-1];

               }
               else if (a[i] > b[j])
               {
                    sum_b += b[j];
                    ++j;
                    // b[j] += b[j-1];
               }
               else
               {
                    if (sum_a > sum_b)
                         sum += sum_a + a[i];
                    else
                         sum += sum_b + b[j];
                    sum_a = 0;
                    sum_b = 0;
                    ++j; ++i;
               }
          }

          if (i == n)
               while (j < m)
               {
                    sum_b+=b[j];
                    ++j;
                    // b[j] += b[j-1];
               }
          else
               while (i < n)
               {
                    sum_a += a[i];
                    ++i;
               }


          if (sum_a > sum_b)
               sum += sum_a;
          else
               sum += sum_b;
          printf("%d\n", sum);
     }
     return 0;
}
