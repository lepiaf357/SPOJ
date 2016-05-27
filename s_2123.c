#include <stdio.h>


int main(void)

{
  int n, a[10000], div, sum, moved;
  
  scanf("%d", &n);
  while (n != -1)
    {
      int i;
      moved = 0;
      for (i = 0, sum = 0; i < n; ++i)
	{
	  scanf("%d", &a[i]);
	  sum += a[i];
	}
      if (sum % n != 0)
	{
	  printf("-1\n");
	  scanf("%d", &n); 
	  continue;
	}
      div = sum / n;
      for (i = 0; i < n; ++i)
	{
	  if (a[i] < div)
	    moved += div - a[i];
	}
      printf("%d\n", moved);
      
      scanf("%d", &n); 
    }

  return 0;
}
    
