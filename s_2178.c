#include <stdio.h>
#include <limits.h>

int main(void)
{
     int a, d, a_min, d_min1, d_min2;
     scanf("%d%d", &a, &d);
     do
     {
          int i, temp;
          a_min = INT_MAX;
          for (i = 1; i <= a; ++i)
          {
               scanf("%d", &temp);
               if (a_min > temp)
                    a_min = temp;
          }
          d_min1 = d_min2 = INT_MAX;
          for (i = 1; i <= d; ++i)
          {
               scanf("%d", &temp);
               if (d_min1 > temp)
               {
                    d_min2 = d_min1;
                    d_min1 = temp;
               } else if (d_min2 > temp)
                    d_min2 = temp;
          }
          if (a_min < d_min2)
               printf("Y\n");
          else
               printf("N\n");
          scanf("%d%d", &a, &d);
     } while(a != 0);



     return 0;
}
