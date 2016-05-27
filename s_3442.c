#include <stdio.h>


int main(void)

{
  int n, a, b, res, i;
  
  scanf("%d", &n);
  
  while (n--)
    {
      scanf("%d%d", &a, &b);
      if (a == 0)
	{
	  printf("0\n");
	  continue;
	}
      if (b == 0)
	{
	  printf("1\n");
	  continue;
	} 
      for (i = (b-1) % 4, res = a; i > 0; i--)
	{
	   //i < (((b % 4) == 0) ? 1 : (b % 4)); ++i)
	  res *= a;
	}

      res = res % 10;

      printf("%d\n", res);
	

    }

  return 0;
}
    
