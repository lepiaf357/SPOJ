#include <stdio.h>

int main(void)
{
     int n, i, b, m, p = 0, br_1 = 0, br_2 = 0, br_3 = 0;

     scanf("%d", &n);

     for(i = 1; i <= n; i++)
     {
          scanf("%d%*c%d", &b, &m);
          if(b == 3)
               br_3++;
          else if(m == 2)
               br_2++;
          else
               br_1++;
     }

     while(br_3 > 0 && br_1 > 0)
     {
          br_3--;
          br_1--;
          p++;
     }
     while(br_2 > 1)
     {
          br_2 -= 2;
          p++;
     }
     if(br_2 > 0 && br_1 > 1)
     {
          br_2--;
          br_1 -= 2;
          p++;
     }
     while(br_1 > 3)
     {
          br_1 -= 4;
          p++;
     }

     p += br_3;
     if(br_2 == 1 && br_1 == 1)
     {
          br_2 = 0;
          br_1 = 0;
          p++;
     }
     if(br_1 == 3)
     {
          br_1 = 0;
          p++;
     }

     p +=br_2;
     if(br_1 == 2)
     {
          br_1 = 0;
          p++;
     }

     p += br_1;

     p++;

     printf("%d\n", p);
     return 0;
}
