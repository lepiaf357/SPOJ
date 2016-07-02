#include <cstdio>

int main()
{
     int t, H, A;

     scanf("%d", &t);

     while (t--)
     {
          int i = 0;
          scanf("%d%d", &H, &A);

          while (H > 0 && A > 0)
          {
               H += 3;
               A += 2;
               i++;

               if ((H-5) > 0 && (A-10) > 0)
               {
                    H -= 5;
                    A -= 10;
                    i++;
               }
               else if((H-20) > 0)
               {
                    H -= 20;
                    A += 5;
                    i++;
               }
               else
               {
                    break;
               }
          }

          printf("%d\n", i);
     }

     return 0;
}
