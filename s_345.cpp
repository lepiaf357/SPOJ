#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> mixtures(101);


int color(int l, int r)
{
        int res = 0;
        for (; l <= r; ++l)
                res = (res % 100 + mixtures [l] % 100) % 100;
        return res;
}

int harry_i(int n)
{
        vector<vector <int> > tab(101, vector<int>(101));

        // for (int i = 0; i < n; ++i)
        //         for (int j = 0; j < n; ++j)
        //         tab[i][j] = 0;
        for (int i = 0; i < n; ++i)
                tab[i][i] = 0;

        for (int i = 1; i < n; ++i)
        {
                for (int j = i, m = 0; j < n; ++j, ++m)
                {
                        int minimum = INT_MAX;
                        for (int k = i; k > 0 ; --k)
                        {
                                int x = j - k;
                                int a = tab[m][x] + tab[x+1][j] + color(m, x)*color(x+1, j);
                                minimum = min(minimum, a);
                        }
                        tab[m][j] = minimum;
                        // printf("i:%d j:%d=  \t%d\n", m, j, tab[m][j]);
                }
        }
        return tab[0][n-1];
}


// int harry_i(int n)
// {
//           vector<vector <int> > tab(101, vector<int>(101));
//           int minimum = INT_MAX;

//           for (int i = 0; i < n; ++i)
//                   tab[i][i] = mixtures[i];

//           for (int k = 1; k <= n-1; k++)
//                   for (int j = n-1; j>= k; j--)
//                   {
//                           int a = 0;
//                           for (int i = j-k+1; i <= j; i++)
//                           {
//                                   a = ((a % 100) + (tab[i][j] % 100)) % 100;
//                                   //                                minimum = min(a, minimum);
//                           }
//                           int b = 0;
//                           for (int m = j; m >= j-k; m--)
//                           {
//                                   b = ((b % 100) + (tab[j-k][m] % 100)) % 100;
//                                   //      minimum = min(b, minimum);
//                           }

//                           minimum = min(a + b + a*b, minimum);
//                           tab[j-k][j] = minimum;
//                   }

//           return tab[0][n-1];
// }

int harry_r(int l, int r)
{
        int minimum = INT_MAX;
        if (l == r)
                return 0;
        for (int i = l; i < r; i++)
        {
                int a = harry_r(l, i) + harry_r(i+1, r) + color(l, i)*color(i+1, r);
                minimum = min(a, minimum);
        }
        return minimum;

}

int main()
{
        int n, temp;
        while (scanf("%d", &n) > 0)
        {
                for (int i = 0; i< n; i++)
                {
                        scanf("%d", &temp);
                        mixtures[i] = temp;
                }
                // printf("%d\n", harry_r(0, n-1));
                printf("%d\n", harry_i(n)); //
        }

        return 0;
}
