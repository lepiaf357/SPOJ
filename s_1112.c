#include <stdio.h>

int main(void)
{
  int n, x, y;
  scanf("%d", &n);

  do
    {
      scanf("%d%d", &x , &y);

      if (x != y && y != x - 2)
	{
	  printf("No Number\n");
	  continue;
	}
      //printf("%d\n", 2 * x - (x == y) ? 0 : 2); //Sta ce da ispise>
      if (x % 2 == 0)
	printf("%d\n", 2 * x - ((x == y) ? 0 : 2));
      if (x % 2 == 1)
	printf("%d\n", 2 * x - 1 - ((x == y) ? 0 : 2));
	
    } while(--n > 0);
  return 0;

}
