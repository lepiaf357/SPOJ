#include <stdio.h>
#include <stdlib.h>


typedef struct
{
     int b;
     int f;
} party;

party p[100];
int tab[100][501];
int aux[100][501];
int max (int a, int b)
{ return a > b ? a : b; }

int party_sch(int n, int B)
{

     for (int i = 0; i <= B; ++i)
     {
          if (i - p[n-1].b < 0)
               tab[n-1][i] = aux[n-1][i] = 0;
          else
          {
               tab[n-1][i] = p[n-1].f;
               aux[n-1][i] = 1;
          }
     }
     for (int i = n-2; i >= 0; --i)
          for (int j = 0; j <= B; ++j)
          {
               if (j - p[i].b < 0)
               {
                    tab[i][j] = tab[i+1][j];
                    aux[i][j] = 0;
               }
               else
               {
                    if (tab[i+1][j] > tab[i+1][j-p[i].b] + p[i].f)
                    {
                         aux[i][j] = 0;
                         tab[i][j] = tab[i+1][j];
                    }
                    else
                    {
                         if (tab[i+1][j] == tab[i+1][j-p[i].b] + p[i].f )
                         {
                              if (tab[i][j-1] == tab[i+1][j-p[i].b] + p[i].f && aux[i][j-1])
                                   aux[i][j] = 1;
                              else
                                   aux[i][j] = 0;
                         }
                         else
                              aux[i][j] = 1;
                         tab[i][j] = tab[i+1][j-p[i].b] + p[i].f;
                    }
               }
          }
     int i = 0; int j = B; int money = 0;
     while (j > 0 && i < n)
     {
          if (aux[i][j] == 0)
               ++i;
          else
          {
               money += p[i].b;
               j -= p[i].b;
               ++i;
          }
     }
     printf("%d ", money);
     return tab[0][B];

}

int compare(const void *a, const void *b)
{
     int m = ((party *)b)->f -  ((party *)a)->f;
     if (m == 0)
          return ((party *)b)->b -  ((party *)a)->b;
     return m;

}

int main(void)
{
     int B, n;

     scanf("%d%d", &B, &n);
     while (B != 0 && n != 0)
     {
          for (int i = 0; i < n; i++)
               scanf("%d%d", &p[i].b, &p[i].f);
          qsort(p, n, sizeof(p[0]), &compare);
          printf("%d\n", party_sch(n, B));
          scanf("%d%d", &B, &n);
     }
     return 0;
}
