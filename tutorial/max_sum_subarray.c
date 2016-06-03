#include <stdio.h>
#include <stdlib.h>

int maxSumSlow(int *a, int x, int y)
{
        int max = 0;
        for (int i = x; i <= y; i++)
        {
                int max_so_far = 0;
                for (int j = i; j <= y; j++)
                {
                        int max_here = 0;
                        for (int k = i; k <= j; ++k)
                                max_here += a[k];
                        if (max_so_far < max_here)
                                max_so_far = max_here;
                }
                if (max_so_far > max)
                        max = max_so_far;
        }
        return max;
}

int maxSumFast(int *a, int x, int y, int n)
{
        int *s = malloc((n+1) * sizeof *s), max = 0;
        s[0] = 0;
        for (int i = 0; i < n; i++)
                s[i+1] = s[i] + a[i];

        /* for (int i = 1; i <= n; i++) */
        /*         printf("%d: %d\n", i, s[i]); */
        /* printf("\n"); */

        for (int i = x; i <= y; i++)
        {
                int max_so_far = 0;
                for (int j = i; j <= y; j++)
                        if (s[j+1] - s[i] > max_so_far)
                                max_so_far = s[j+1] - s[i];
                if (max < max_so_far)
                        max = max_so_far;
        }
        return max;
}

int main(void)
{
        int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

        printf("maxSumSlow od 3 do 7: %d\n", maxSumSlow(a, 3, 7));
        printf("maxSumFast od 3 do 7: %d\n", maxSumFast(a, 3, 7, sizeof a / sizeof *a));
        return 0;
}
