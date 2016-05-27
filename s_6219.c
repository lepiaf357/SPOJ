#include <stdio.h>

int table[2001][2001];

int cost_of_insert()
{ return 1; }
int cost_of_delete()
{ return 1; }
int cost_of_replace(char a, char b)
{
        if (a == b)
                return 0;
        return 1;
}
int min (int a, int b, int c)
{
        if (b < a)
                if (c < b)
                        return c;
                else
                        return b;
        else
                if (c < a)
                        return c;
                else
                        return a;
}

int editDist(char *a, char *b, int n, int m)
{
        int i, j;

        for (j = 0; j <= m; ++j)
                table[n][j] = m - j;
        for (i = 0; i <= n; ++i)
                table[i][m] = n - i;

        for (i = n - 1; i >= 0; --i)
                for (j = m - 1; j >= 0; --j)
                {
                        table[i][j] = min(
                                table[i+1][j+1] + cost_of_replace(a[i], b[j]),
                                table[i][j+1] + cost_of_insert(),
                                table[i+1][j] + cost_of_delete()
                                );
                }
        return table[0][0];
}

int editDist_r(char *a, char *b, int n, int m, int i, int j)
{
        if (i == n && j == m)
                return 0;
        if (i == n)
                return cost_of_insert() +            editDist_r(a, b, n, m, i, j+1);
        if (j == m)
                return cost_of_delete() +            editDist_r(a, b, n, m, i+1, j);
        return min(
                cost_of_replace(a[i], b[j]) + editDist_r(a, b, n, m, i+1, j+1),
                cost_of_insert() +            editDist_r(a, b, n, m, i, j+1),
                cost_of_delete() +            editDist_r(a, b, n, m, i+1, j)
                );

}

int main(void)
{
        char a[2001], b[2001];
        int n, i, j;

        scanf("%d", &n);

        while (n--)
        {
                scanf("%s", a);
                for (i = 0; a[i] != '\0'; ++i);
                scanf("%s", b);
                for (j = 0; b[j] != '\0'; ++j);

                //printf("%d\n", editDist_r(a, b, i, j, 0, 0));
                printf("%d\n", editDist(a, b, i, j));
        }
        return 0;
}
