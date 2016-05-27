#include <stdio.h>

int main(void)
{
  long long in;
  scanf ("%lld", &in);
  if (in == 1 || in == 0)
    {
      printf("TAK\n");
      return 0;
    }
  while (in != 1)
    {
      if (in % 2 == 0)
	{
	  in /= 2;
	}
      else
	{
	  printf("NIE\n");
	  return 0;
	}
    }
  printf("TAK\n");
  return  0;
  
}
