#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIEVE_SIZE 1000000000
int main(void)
{
        char *sieve, *sieve_second;
        long i, j, t, v, x, y, z, n, left, right;

        x = sqrt(SIEVE_SIZE);
        y = sqrt(x);
        z = y /3;
        sieve = malloc((x /3) * sizeof *sieve);

        for (i = 5, t = 2; i < y; i+= t, t = 6 - t)
        {
                if (sieve[i /3] == 0)
                {
                        for (j = i*i, v = t; j < z; j += v*i, v = 6-v)
                                sieve[j /3] = 1;
                }
        }
        scanf("%lu", &n);
        for (i = 0; i < n; ++i)
        {
                scanf("%lu", &left);
                scanf("%lu", &right);
                sieve_second = calloc((right-left + 1) ,  sizeof *sieve_second);
                x = sqrt(right-1) + 1;
                y = left /2;
                y *= 2;
                if (left % 2 != 0 || left == 2)
                {
                        y+= 2;
                        if (left == 1)
                        {
                                sieve_second[0] = 1;
                                y += 2;
                        }
                }

                for (; y <= right; y+= 2)
                {
                        sieve_second[y - left] = 1;
                }
                y = left /3;
                y *= 3;
                if (left %3 != 0 || left == 1 || left == 3)
                {
                        y += 3;
                        if (left == 1 || left == 2 || left == 3)
                                y += 3;
                }
                for (; y <= right; y+= 3)
                {
                        sieve_second[y - left] = 1;
                }
                for (j = 5, t = 2; j <= x; j+= t, t = 6 - t)
                {
                        if (sieve[j /3] != 0) continue;
                        y = left /j;
                        y *= j;
                        if (y == 0) y += 2*j;
                        if (y - left < 0) y += j;
                        for (; y <= right; y += j)
                        {
                                sieve_second[y - left] = 1;
                        }
                }
                for(v = 0; v <= right - left; ++v)
                {
                        // if ( v <= 37)
                        // printf("%d\n", sieve_second[v]);
                        if (sieve_second[v] == 0)
                                printf("%lu\n", v + left);
                }
                printf("\n");
                free(sieve_second);
        }
        free(sieve);
        /* if (i < 5)
           printf("2\n3\n");
           for(i = 5, t = 2; i < 10; i+= t, t = 6 - t)
           {
           if (sieve[i /3] == 0)
           printf("%lu\n", i);
           }
        */
        return 0;
}
