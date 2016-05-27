#include <stdio.h>

int a[800];

int main(void)
{
     int t, i, iterations = 0;
     char num[11];
     scanf("%s", num);

     while (1)
     {
          for (i = 0, t = 0; num[i] != '\0'; ++i)
               t += (num[i] - '0') * (num[i] - '0');

          //printf("t: %d\n", t);
          if (a[t])
          {
               printf("-1\n");
               return 0;
          }
          a[t] = 1;
          ++iterations;
          if ( t == 1)
          {
               printf("%d\n", iterations);
               return 0;
          }
          snprintf(num, sizeof num, "%d", t);
     }
     return 0;
}
