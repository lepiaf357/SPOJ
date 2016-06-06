#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char a[6101];
int t[6101][6101];

int pal_r(int i, int j)
{
     if (j <= i)
          return 0;

     if (a[i] == a[j])
     {
          i++;
          j--;
     }

     if (j <= i)
          return 0;

     return min(pal_r(i+1, j), pal_r(i, j-1)) + 1;
}

int pal(int n)
{
     for (int i = 0; i < n; i++)
          t[i][i] = 0;

     for (int i = n-2; i >= 0; i--)
          for (int j = i + 1; j < n; j++)
     // for (int i = 1; i < n; ++i)
     //      for (int j = 0, k = i; k < n; j++, k++)
          {
               // if (a[k] == a[j])
               //      t[j][k] = t[j+1][k-1];
               // else
               //      t[j][k] = min(t[j+1][k], t[j][k-1]) + 1;

               if (a[i] == a[j])
                    t[i][j] = t[i+1][j-1];
               else
                    t[i][j] = min(t[i+1][j], t[i][j-1]) + 1;
          }

     return t[0][n-1];
}
int main()
{
     int t;
     scanf("%d", &t);

     while (t--)
     {
          scanf("%s", a);
          printf("%d\n", pal(strlen(a)));
          // printf("%d\n", pal_r(0, strlen(a)-1));

     }
     return 0;
}
