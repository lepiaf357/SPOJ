#include <cstdio>
#include <vector>

using namespace std;

int main()
{
     int t, n;
     int no = 1;

     scanf("%d", &t);

     while (t--)
     {
          scanf("%d", &n);
          vector<int> a(n);
          int tmp;
          int j = -1;
          for (int i = 0; i < n; i++)
          {
               scanf("%d", &tmp);
               if (tmp < 0)
                    j = i;
               a[i] = tmp;
          }

          if (j == -1)
               printf("Scenario #%d: 1\n", no);
          else
          {
               long long sum = 0;

               for (int i = j; i >= 0; i--)
               {
                    if (a[i] < 0 && sum > 0)
                         sum = 0;

                    sum += a[i];
               }
               if (sum >= 0)
                    printf("Scenario #%d: 1\n", no);
               else
               {
                    sum = -sum + 1;
                    printf("Scenario #%d: %lld\n", no, sum);
               }
          }
          no++;
     }

     return 0;
}
