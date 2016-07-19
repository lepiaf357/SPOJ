#include <cstdio>
#include <algorithm>

using namespace std;

int a[1001];
int tab[1001][1001];

int game_r(int i, int j)
{
     if (i > j)
          return 0;

     int f1 = (a[i+1] > a[j]);
     int f2 = (a[j-1] > a[i]);

     if (f1 && f2)
          return max(a[i] + game_r(i+2, j), a[j] + game_r(i,j-2));
     else if (!f1 && !f2)
          return max(a[i] + game_r(i+1, j-1), a[j] + game_r(i+1,j-1));
     else if (f1 && !f2)
          return max(a[i] + game_r(i+2, j), a[j] + game_r(i+1,j-1));
     else
          return max(a[i] + game_r(i+1, j-1), a[j] + game_r(i,j-2));
}

int game(int n)
{

}

int main()
{
     int n;

     while (1)
     {
          scanf("%d", &n);

          if (n == 0)
               break;

          for (int i = 0; i < n; i++)
               scanf("%d", &a[i]);

          printf("%d\n", game_r(0,n-1));
     }

     return 0;
}
