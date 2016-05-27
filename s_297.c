#include <stdio.h>

int a[100000];

int compare(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}
int main()
{
        int lo, hi, mid, n, cow, t;

        scanf("%d", &t);

        while(t > 0)
        {
                int i;

                scanf("%d%d",&n,&cow);
                for(i = 0; i < n; i++)
                        scanf("%d",&a[i]);

                qsort(a, n, sizeof(a[0]), &compare);

                lo = a[1] - a[0];
                hi = a[n-1] - a[0];

                while(lo < hi)
                {
                        mid = lo + (hi - lo + 1) / 2;
                        int j, cur = 1;

                        for(i = 1, j = 0; i < n; i++)
                                if(a[i] - a[j] >= mid)
                                {
                                        cur++;
                                        j = i;
                                }

                        if(cur < cow)
                                hi = mid - 1;
                        else
                                lo = mid;
                }

                printf("%d\n", lo);
                t--;
        }

        return 0;
}
