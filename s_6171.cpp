#include <cstdio>

int a[1000000];



int main()
{
     int n, t, i;
     scanf("%d", &t);

     while (t--)
     {
          scanf("%d", &n);
          for (i = 0; i < n; i++)
               scanf("%d", &a[i]);
          int b = a[0];
          int count = 1;
          for (i = 1; i < n; i++)
          {
               if (a[i] == b)
                    count++;
               else
                    count--;
               if (count == 0)
               {
                    b = a[i];
                    count = 1;
               }
          }
          count = 0;
          for (i = 0; i < n; i++)
               if (a[i] == b)
                    count++;
          if (count > n/2)
               printf("YES %d\n", b);
          else
               printf("NO\n");
     }
     return 0;
}
