#include <stdio.h>
#include <limits.h>

typedef struct
{
        int value, weight;
} pig;

int min (int a, int b, int c)
{
        if (a < b)
                if (a < c)
                        return a;
                else
                        return c;
        else//if (b < a)
                if (b < c)
                        return b;
                else
                        return c;

}

int t[501][10001];

int pig_bank(pig *a, int n, int W)
{
        t[n-1][0] = 0;
        for (int i = 1; i <= W; i++)
                if (i - a[n-1].weight >= 0 && t[n-1][i - a[n-1].weight] != INT_MAX)
                        t[n-1][i] = a[n-1].value + t[n-1][i - a[n-1].weight];
                else
                        t[n-1][i] = INT_MAX;
        for (int i = n-2; i >= 0; --i)
        {
                t[i][0] = 0;
                for (int j = 1; j <= W; j++)
                {
                        if (j - a[i].weight < 0)
                                t[i][j] = t[i+1][j];
                        else
                        {
                                int x = t[i+1][j], y = INT_MAX, z = INT_MAX;
                                if (t[i+1][j-a[i].weight] != INT_MAX)
                                        y = a[i].value + t[i+1][j-a[i].weight];
                                if (t[i][j-a[i].weight] != INT_MAX)
                                        z = a[i].value + t[i][j-a[i].weight];
                                t[i][j] = min(x, y, z);
                        }
                }
        }
        return t[0][W];
}

int pig_bank_r(pig *a, int n, int i, int W)
{
        if (W < 0 || i >= n)
                return INT_MAX;
        if (W == 0)
                return 0;
        int x = 0, y = 0, z = 0;

        y = pig_bank_r(a, n, i,  W-a[i].weight);
        if (y != INT_MAX)
                y += a[i].value;

        x = pig_bank_r(a, n, i+1, W-a[i].weight);
        if (x != INT_MAX)
                x += a[i].value;


        z = pig_bank_r(a, n, i+1, W);


        return min(x, y, z);
}

int main()
{
        int n, empty, filled, t;
        pig a[501];

        scanf("%d", &n);

        while(n--)
        {
                scanf("%d%d%d", &empty, &filled, &t);

                for(int i = 0; i < t; i++)
                        scanf("%d%d", &a[i].value, &a[i].weight);
                /* int res = pig_bank_r(&a[0], t, 0, filled-empty); */
                int res = pig_bank(&a[0], t, filled-empty);
                if (res == INT_MAX)
                        printf("This is impossible.\n");
                else
                        printf("The minimum amount of money in the piggy-bank is %d.\n", res);

        }

        return 0;
}
