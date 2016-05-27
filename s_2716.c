#include <stdio.h>
#include <math.h>

int main(void)
{
     int n;
     double a, b, c, d;


     scanf("%d", &n);

     while (n--)
     {
          double s;
          scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
          s = (a + b + c + d) / 2;

          printf("%.2lf\n", sqrt((s-a)*(s-b)*(s-c)*(s-d)));

     }
     return 0;
}
