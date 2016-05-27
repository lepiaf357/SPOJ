#include <stdio.h>


int main()
{
  int n, i, br=0;

  scanf("%d",&n);

  for(i = 1; i*i <= n; i++)
     br += (n - i*i) / i + 1;
            

  printf("%d\n", br);
  return 0;
}

