#include <stdio.h>

int main(void)

{
  int n, br, stepen, rez;
  scanf("%d", &n);

  do
    {
      rez = 0;
      scanf("%d", &br);
      stepen = 5;

      while (br >= stepen)
	{
	  rez += br / stepen;
	  stepen *= 5;
	}
      printf("%d\n", rez);

    }while (--n > 0);

}
