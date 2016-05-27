#include <stdio.h>

typedef struct
{
     int s;
     int v;
} bag;

bag items[2000];

int max (int a, int b)
{ return a > b ? a : b; }

int knapsack_r(int j, int n, int S)
{
     if (j == n)
          return 0;
     if (S-items[j].s >= 0)
          return max(knapsack_r(j+1, n, S), knapsack_r(j+1, n, S-items[j].s)+items[j].v);
     else
          return knapsack_r(j+1, n, S);
}

int tab[2000][2001];

int knapsack_i(int n, int S)
{
     for (int i = 0; i <= S; ++i)
     {
          if (i < items[n-1].s)
               tab[n-1][i] = 0;
          else
               tab[n-1][i] = items[n-1].v;
     }
     for (int i = n-2; i >= 0; --i)
          for (int j = 0; j <= S; ++j)
          {
               if (j-items[i].s < 0)
                    tab[i][j] = tab[i+1][j];
               else
                    tab[i][j] = max (tab[i+1][j], tab[i+1][j-items[i].s]+items[i].v);
          }
     return tab[0][S];
}

int main(void)
{
     int S, n;

     scanf("%d%d", &S, &n);
     for (int i = 0; i < n; ++i)
          scanf("%d%d", &items[i].s, &items[i].v);

     //printf("%d", knapsack_r(0, n, S));
     printf("%d", knapsack_i(n, S));

     return 0;
}
