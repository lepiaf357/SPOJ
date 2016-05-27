#include <stdio.h>


int main(void)
{
  int n;

  scanf("%d", &n);
  while(n)
    {
      int i, sum=0;
      for(i = 0; i < n; ++i)
	sum += (n- i) * (n-i);

      printf("%d\n",sum);
        scanf("%d", &n);
    }

  return 0;
}
