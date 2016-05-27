#include <stdio.h>


int main(void)

{
  int a, b, c;

  scanf("%d%d%d",&a, &b, &c);

  while(a!=0 || b!=0 || c!=0)
    {
      int temp = b - a;
      if(temp + b == c)
	{
	  printf("AP %d\n", c + temp);
	}
      else
	{
	  temp = b / a;
	  printf("GP %d\n", c * temp);
	}
      
      scanf("%d%d%d", &a, &b, &c);     
    }

  return 0;
}
    
