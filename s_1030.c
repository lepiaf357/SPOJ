#include <stdio.h>

int main()
{
  int n;
  long long k;

  scanf("%d", &n);

  while(n != 0)
    {
      scanf("%lld", &k);
      long long i, cnt;
      int res;
      printf("%lld\n", 250 * (k-1) +192);
      /* printf("%lld\n", ((k % 2 == 0) ? ((k + 1)/2-1)*1000 + 692 :  ((k + 1)/2-1)*1000 + 192)); */
      /* n--; */
      /* for (i = 192, cnt = 0; ; i++) */
      /* 	{ */
      /* 	  res = i % 1000; */
      /* 	  res = res * res * res; */
      /* 	  if (res % 1000 == 888) */
      /* 	    { */
      /* 	      ++cnt; */
      /* 	      printf("%lld\n", i); */
      /* 	    } */
      /* 	  if (cnt == k) */
      /* 	    { */
      /* 	      printf("%lld\n", i); */
      /* 	      break; */
      /* 	    } */
      /* 	} */
      --n;
      
    }
  
  return 0;
}
