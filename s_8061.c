#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int kids[20000];

int cmp(const void* a, const void* b)
{
     return *(int*)a - *(int*)b;
}

int main(void)
{
     int t, n, k;

     scanf("%d", &t);

     while(t--)
     {
          int min = INT_MAX;
          scanf("%d%d", &n, &k);
          for (int i = 0; i < n; ++i)
               scanf("%d", &kids[i]);
          qsort(kids, n, sizeof(kids[0]), cmp);
          for (int i = 0; i < n-(k-1); ++i)
               if (min > kids[i+(k-1)] - kids[i])
                    min = kids[i+(k-1)] - kids[i];
          printf("%d\n", min);
     }
     return 0;
}
