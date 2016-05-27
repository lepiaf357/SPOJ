#include <stdio.h>


int puta(int *fact, int *new_fact, int len, int num, int shift)
{
  int i, z = 0;
  
   for (i = 0; i < len; ++i)
     {
	int temp = fact[i] * num + z;
        new_fact[i] = temp % 10;
        z = temp / 10;
     }
   if (z)
     {
       new_fact[i] = z;
       ++len;
     }   
   if (shift)
     {
       for (i = len; i > 0; --i)
	 new_fact[i] = new_fact[i-1];
       new_fact[0] = 0;
       ++len;
     }
   return len;
}


int plus(int *fact, int *new_fact, int len_fact, int len_new_fact)
{
  int i, z = 0;
  /* for (i = 0; i < len_fact; ++i) */
  /*   printf("%d", fact[i]); */
  /* printf("\n"); */
    
  /* for (i = 0; i < len_new_fact; ++i) */
  /*   printf("%d", new_fact[i]); */
  /* printf("\n"); */
  while (len_fact < len_new_fact)
    {
      fact[len_fact] = 0;
      ++len_fact;
    }

  for (i = 0; i < len_new_fact; ++i)
    {
      int temp = fact[i] + new_fact[i] + z;
      fact[i] = temp % 10;
      z = temp / 10;
    }
  
   if (z)
     {
       fact[i] = z;
       ++len_fact;
     }
   return len_fact;
}


int main(void)
{
  int n, fact[250], new_fact[250], new_len, z, i, j, br, k1, k2, fact_len, k;

  scanf("%d", &n);

  while (n-->0)
    {
      scanf("%d", &br);
      if (br == 1)
	{
	  printf("1\n");
	  continue;
	}
      fact[0] = 1;
      fact_len = 1;
      for (i = 1; i <= br; ++i)
	{
	  if (i <= 9)
	    fact_len = puta(fact, fact, fact_len, i, 0);
	  else if(i==100)
	    {
	    fact_len = puta(fact, fact, fact_len, 1, 1);
	    fact_len = puta(fact, fact, fact_len, 1, 1);
	    }
	  else
	    {
	      new_len = puta(fact, new_fact, fact_len, i/10, 1);	       
	      fact_len = puta(fact, fact, fact_len, i%10, 0);
	      fact_len = plus(fact, new_fact, fact_len, new_len);	
	    }
	}
      for (i = fact_len-1; i >= 0; --i)
	printf("%d", fact[i]);
      printf("\n");
      
    }	   

  return 0;
}

    /*   fact[0] = 1; */
    /*   fact_len = 0; */
    /*   for (j = 1; j <= br; ++j) */
    /* 	{ */
    /* 	  k2 = j % 10; */
    /* 	  k1 = j / 10; */
    /* 	  new_len = fact_len; */
    /* 	  z = 0; */
    /* 	  for (i = 0; i <= fact_len; ++i) */
    /* 	    { */
    /* 	      int temp = fact[i] * k2 + z; */
    /* 	      new_fact[i] = temp % 10; */
    /* 	      z = temp / 10; */
    /* 	    } */
    /* 	  if (z) */
    /* 	    { */
    /* 	      new_fact[i] = z; */
    /* 	      ++new_len; */
    /* 	    } */
    /* 	  z = 0; */
    /* 	  if (k1) */
    /* 	    { */
    /* 	      for (i = 0, k = 0; i <= fact_len; ++i) */
    /* 		{ */
    /* 		  int temp = fact[i] * k1 + z; */
    /* 		  if (i < fact_len) */
    /* 		    k = new_fact[i+1] + temp % 10; */
    /* 		  else */
    /* 		    k = temp % 10; */
    /* 		  new_fact[i+1] = k % 10; */
    /* 		  z = temp / 10 + k / 10; //max 9 */
    /* 		} */
    /* 	      if (z) */
    /* 		{ */
    /* 		  new_fact[i] = z; */
    /* 		  ++new_len; */
    /* 		} */
    /* 	    } */
    /* 	  fact_len = new_len; */
    /* 	  for (i = 0; i <= new_len; ++i) */
    /* 	    { */
    /* 	      fact[i] = new_fact[i];	       */
    /* 	    } */
    /* 	} */
    /*   for (i = 0; i <= fact_len; ++i) */
    /* 	printf("%d", fact[fact_len - i]); */
    /*   printf("\n"); */
    /* } */
