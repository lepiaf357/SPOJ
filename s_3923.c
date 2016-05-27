#include <stdio.h>

int max(int a, int b, int c)
{
        if(b > a)
                if(b > c)
                        return b;
                else
                        return c;
        else
                if(a > c)
                        return a;
                else
                        return c;
}

int harry_r(int a[101][101], int n, int m, int i, int j)
{
        if(i == n)
                return 0;

        if(j == 0)
                return a[i][j] + max(0, harry_r(a, n, m, i+1, j), harry_r(a, n, m, i+1, j+1));
        else if(j == m-1)
                return a[i][j] + max(harry_r(a, n, m, i+1, j-1),  harry_r(a, n, m, i+1, j), 0);

        return a[i][j] + max(harry_r(a, n, m, i+1, j-1), harry_r(a, n, m, i+1, j), harry_r(a, n, m, i+1, j+1));
}

int main()
{
        int a[101][101], table[101][101];
        int t, n, m;

        scanf("%d", &t);

        while(t != 0)
        {
                int i, j;
                scanf("%d%d", &n, &m);
                t--;

                for(i = 0; i < n; i++)
                        for(j = 0; j < m; j++)
                                scanf("%d", &a[i][j]);


                for(j = 0; j < m; j++)
                        table[n-1][j] = a[n-1][j];

                for(i = n-2; i >=0; i--)
                        for(j = 0; j < m; j++)
                        {
                                if(j == 0)
                                        table[i][j] = a[i][j] + max(0, table[i+1][j], table[i+1][j+1]);
                                else if(j == m-1)
                                        table[i][j] = a[i][j] + max(table[i+1][j-1], table[i+1][j], 0);
                                else
                                        table[i][j] = a[i][j] + max(table[i+1][j-1], table[i+1][j], table[i+1][j+1]);
                        }

                int max = table[0][0];

                 for(j = 1; j < m; j++)
                         if(table[0][j] > max)
                                 max = table[0][j];

                 printf("%d\n", max);
        }


        return 0;
}
