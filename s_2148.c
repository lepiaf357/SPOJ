#include <stdio.h>


int main()
{

  long long br_ch, i, candyStore, n, tmp;
  
  scanf("%lld", &n);

  while(n != 0)
    {
      scanf("%lld", &br_ch);

      candyStore = 0;

      for (i = 0; i < br_ch; i++)
	{
	  scanf("%lld", &tmp);
	  candyStore = (candyStore + tmp) % br_ch;
	}

      if(candyStore == 0)
	printf("YES\n");
      else
	printf("NO\n");
      
      n--;
    }
  return 0;
}
