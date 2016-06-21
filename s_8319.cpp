#include <cstdio>

int main()
{
     int sum = 0;
     int b;
     int a, c;

     for (int i = 0; i < 10; i++)
     {
          scanf("%d", &b);
          if (sum + b == 100)
          {
               sum += b;
               break;
          }
          if (sum + b > 100)
          {
               a = 100 - sum;
               c = sum + b - 100;
               if (c <= a)
                    sum += b;
               break;

          }
          sum += b;
     }
     printf("%d\n", sum);

     return 0;
}
