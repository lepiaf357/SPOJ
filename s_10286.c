#include <stdio.h>

int main()
{
     int t, n, d, k;

     scanf("%d", &t);
     while(t != 0)
     {
          scanf("%d%d%d", &n, &k, &d);
          int b = -1;
          for(int i = 0; i < n; i++)
          {
               int tmp;
               scanf("%d", &tmp);

               while(tmp > d)
               {
                    tmp -= d;
                    k--;
               }
               if(k <= 0)
                    b = 1;
          }
          if(b == 1)
               printf("YES\n");
          else
               printf("NO\n");
          t--;
     }
     return 0;
}
