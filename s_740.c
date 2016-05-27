#include <stdio.h>
#include <stdlib.h>

int max (int a, int b)
{ return a > b ? a: b; }

int cows(int *v, int n)
{
     int *tab = malloc(n*n*sizeof *tab);
     int  a=n ;
     for (int j = 0, k = 0; k < n; ++k, ++j)
          tab[j * n + k] = v[j]*a;

     for (int i = 1; i < n; ++i)
     {
          --a;
          for (int j = 0, k = i; k < n; ++k, ++j)
               tab[j * n + k] = max (tab[(j+1) * n + k] + v[j]*a, tab[j*n+(k-1)]+v[k]*a);

     }
     for (int i = 0; i < n; ++i)
     {
          for (int j = 0; j < n; ++j)
               printf("%d ", tab[i*n+j]);
          printf("\n");
     }
     return tab[n-1];
}


int main(void)
{
     int n, *v;

     scanf("%d", &n);
     v = malloc(n * sizeof *v);
     for (int i = 0; i < n; ++i)
          scanf("%d", &v[i]);

     printf("%d\n", cows(v, n));

     return 0;
}
