#include <stdio.h>
#include <string>



       void qsort(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *));


int compare(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;  
}

int main()
{
  int n, blanum, man[1000], woman[1000], i, sum = 0;

  scanf("%d", &n);

  while(n > 0)
    {
      scanf("%d", &blanum);

      for(i = 0; i < blanum; i++)
	scanf("%d", &man[i]);

      for(i = 0; i < blanum; i++)
	scanf("%d", &woman[i]);

      qsort(man, blanum, sizeof(man[0]), &compare);
      qsort(woman, blanum, sizeof(woman[0]), &compare);

      sum = 0;
      for(i = 0; i < blanum; i++)
	sum += man[i] * woman[i];

      printf("%d\n", sum);

      dasda
    }
  return 0;
}
