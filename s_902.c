#include <stdio.h>


int main()
{
  double in;
  int i;

  while (1)
    {
      int count = 0;
      scanf("%lf", &in);
      if (in == 0.0)
	break;
      for (i = 2; ; i++)
	{
	  in -= 1/(double)i;
	  ++count;
	  if (in <= 0.0)
	    {
	      printf("%d card(s)\n", count);
	      break;
	    }
	}
      
    }

  return 0;
}
