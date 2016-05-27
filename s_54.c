#include <stdio.h>

void minus(int * a, int * b, int n, int m, int * ret)
{
     int i, j;

     for(i=n-1, j=m-1; j >= 0; --i, --j)
     {
          if (a[i] < b[j])
          {
               ret[i] = a[i] + 10 - b[j];
               a[i-1]--;
          }
          else
               ret[i] = a[i] - b[j];
     }
     for (;i >= 0; --i)
          if(a[i] == -1)
          {
               ret[i] = 9;
               a[i-1] --;
          }
          else
           ret[i] = a[i];
}

void div_2(int * a, int n, int *ret)
{
     int i;
     for (i = n-1; i >= 0; --i)
     {
          ret[i] = a[i] / 2;
          if (a[i] % 2 != 0)
               ret[i+1] += 5;
     }
}

int main(void)
{
     int n = 10;
     int sum[101], sum1[101], nat[101], kla[101], x[101] ;
     while (n--)
     {
          int sum_len, x_len, i;
          char c;
          // scanf("%s%s", sum, x);
          sum_len = 0;
          while(1)
          {
               c = getchar();
               if(c < '0' || c > '9')
                    break;
               sum[sum_len] = c - '0';
               sum1[sum_len] = c - '0';

               sum_len++;
          }
          x_len = 0;
          while(1)
          {
               c = getchar();
               if(c < '0' || c > '9')
                    break;
               x[x_len++] = c - '0';
          }

          minus(sum, x, sum_len, x_len, nat);
          div_2(nat, sum_len, x);
          minus(sum1, x, sum_len, sum_len, kla);

          for (i=0; kla[i] == 0; ++i);
          if(i >= sum_len)
               printf("0");
          for (; i < sum_len; ++i)
               printf("%d", kla[i]);
          printf("\n");
          for (i=0; x[i] == 0; ++i);
          if(i >= sum_len)
               printf("0");
          for (; i < sum_len; ++i)
               printf("%d", x[i]);
          printf("\n");
     }
     return 0;
}
