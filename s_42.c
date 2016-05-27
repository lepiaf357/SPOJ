#include <stdio.h>

int reverse(int br1)
{
  int n_br = 0;
  while (br1 != 0)
    {
      n_br = n_br * 10 + br1%10;
      br1 /= 10;
    }
  return n_br;
}
int main(void)
{
  int n, br1, br2, i;

  scanf ("%d", &n);

  for (i = 0; i < n; ++i)
    {
      scanf("%d%d", &br1, &br2);

      printf("%d\n", reverse(reverse(br1) + reverse(br2)));
    }

  return 0;
}
