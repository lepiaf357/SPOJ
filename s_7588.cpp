#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<vector <int> > tab(101, vector<int>(101));
// if (j == 0)
// {
//      desno;
//      ispod;
// }
// else if (j == n-1)
// {
//      levo;;
//      ispod;
// }
// else
// {
//      levo;
//      desno;
//      ispod;
// }

int miser_i(vector<vector <int> > &a)
{
     for (int i = 0; i < m; ++i)
          tab[n-1][i] = a[n-1][i];
     for (int i = n-2; i >= 0; --i)
     {
          tab[i][0] = min(tab[i+1][0], tab[i+1][1]) + a[i][0];
          for (int j = 1; j < m-1; ++j)
          {
               tab[i][j] = min(min(tab[i+1][j-1], tab[i+1][j]), tab[i+1][j+1]) + a[i][j];
          }
          tab[i][m-1] = min(tab[i+1][m-1], tab[i+1][m-2]) + a[i][m-1];

     }
     int temp = tab[0][0];
     for (int i = 1; i < m; ++i)
     {
          temp = min(temp, tab[0][i]);
     }
     return temp;

}

int miser_r(vector<vector <int> > &a, int i, int j)
{
     int x = INT_MAX, y = INT_MAX, z = INT_MAX;
     if (i == n)
          return 0;

     if (j != 0)
     {
          x = miser_r(a, i+1, j-1);
          if (x != INT_MAX)
               x += a[i][j];
     }
     if (j != n-1)
     {
          y = miser_r(a, i+1, j+1);
          if (y != INT_MAX)
               y += a[i][j];
     }

     z = miser_r(a, i+1, j);
     if (z != INT_MAX)
          z += a[i][j];

     return min(min(x, y), z);
}

int main()
{
     int t, res = INT_MAX;

     scanf("%d%d", &n, &m);
     vector<vector <int> > a(n, vector<int>(m));

     for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
          {
               scanf("%d", &t);
               a[i][j] = t;
          }
     // for (int i = 0; i < m; ++i)
     // {
     //      int temp = min(miser_r(a, 0, i), res);
     //      res = temp;
     // }
     printf("%d\n", miser_i(a));

     return 0;
}
