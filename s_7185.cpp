#include <cstdio>

int main()
{
     int a[8];

     while (1)
     {
          scanf("%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]);
          int max = 0;

          if (a[0] < 0)
               break;

          for (int i = 0; i < 4; i++)
          {
               if ((((a[i]-1) / a[i+4]) + 1) > max)
                    max = ((a[i]-1) / a[i+4]) + 1;
          }

          for (int i = 0; i < 4; i++)
          {
               int t = max * a[i+4] - a[i];
               printf("%d ", t);
          }

          printf("\n");
     }
     return 0;
}
