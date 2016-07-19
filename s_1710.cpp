#include <cstdio>
#include <algorithm>

using namespace std;

int a[1001];
int tab[1003][1003];

int game_r(int i, int j)
{
     if (i >= j)
          return 0;

     int f1 = (a[i+1] >= a[j]);
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
    for (int k = 1; k < n; k++)
        for (int i = 0, j = k; i < n-k; i++, j++)
        {
            int f1 = (a[i+1] >= a[j]);
            int f2 = (a[j-1] > a[i]);

            if (f1 && f2)
                tab[i][j] = max(a[i] + tab[i+2][j], a[j] + tab[i][j-2]);
            else if (!f1 && !f2)
                tab[i][j] = max(a[i] + tab[i+1][j-1], a[j] + tab[i+1][j-1]);
            else if (f1 && !f2)
                tab[i][j] = max(a[i] + tab[i+2][j], a[j] + tab[i+1][j-1]);
            else
                tab[i][j] = max(a[i] + tab[i+1][j-1], a[j] + tab[i][j-2]);
        }

    return tab[0][n-1];
}

int main()
{
     int n, b = 0;

     while (1)
     {
          scanf("%d", &n);

          if (n == 0)
               break;

          b++;
          int sum = 0;

          for (int i = 0; i < n; i++)
          {
               scanf("%d", &a[i]);
               sum += a[i];
          }

          int res = 2*game(n)-sum;
          printf("In game %d, the greedy strategy might lose by as many as %d points.\n", b, res);
     }

     return 0;
}
