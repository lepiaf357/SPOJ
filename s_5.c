#include <stdio.h>

int clear_niz(int *niz, int *niz_len, int *head, int *tail)
{
  int curr = *head, tmp;
  while (curr <= *niz_len)
    niz[curr++] = 0;
  *tail = *niz_len;
  while (1)
    {
      --(*head);
      if (*head == 0)
	{
	 niz[*head] = 1;
	 ++(*niz_len);
	 break;
	}
      tmp = niz[*head] + 1;
      niz[*head] = tmp;
      if (tmp == 10)
        niz[*head] = 0;
      else
	{
	  *head = 1;
	  break;
	}
    }
  return 1;
}

int main(void)
{

  int n, niz[1000001], niz_len, i, head, tail;

  scanf("%d", &n);
  getchar();
  while (n--)
    {
      int flag = 1, carry = 0, again = 1;

      niz[0] = 0;
      for (i=1; ; ++i)
      	{
      	  char c = getchar();
      	  if (c < '0' || c > '9')
      	    break;
      	  niz[i] = c - '0';
      	}
      niz_len = --i;
      head = 1;
      tail = niz_len;
      if (niz_len == 1)
	{
	  printf("%d\n", (niz[1] == 9) ? 11 : ++niz[1]);
	  continue;
	}
      while (again)
	{
	  if (niz_len % 2 == 0)
	    {
	      while (head != tail-1)
		{
		  if ((niz[head] <= niz[tail]) && flag)
		    flag = 1;
		  else
		    flag = 0;
		  niz[tail] = niz[head];
		  ++head; --tail;
		}
	      if (niz[head] == niz[tail])
		{		 
		  if (flag)
		    {
		      niz[head]++;
		      if (niz[head] == 10)
			{
			  again = clear_niz(niz, &niz_len, &head, &tail);//
			  continue;
			}
		      
		    }
		  niz[tail] = niz[head];
		}
	      else
		{
		  if (niz[head] <= niz[tail])
		    niz[head]++;
		  niz[tail] = niz[head];
		}
	    }
	  else
	    {
	      while (head != tail)
		{
		  if ((niz[head] <= niz[tail]) && flag)
		    flag = 1;
		  else
		    flag = 0;
		  niz[tail] = niz[head];
		  ++head; --tail;
		}
	      if (flag)
		niz[head]++;
	      if (niz[head] == 10)
		{
		  again = clear_niz(niz, &niz_len, &head, &tail);//
		  continue;
		}
	    }
	  again = 0;
	}
      if (niz[0] == 0)
	{
	  for (i=1; i <= niz_len; ++i)
	    printf("%d", niz[i]);
	}
      else
	for (i=0; i < niz_len; ++i)
	  printf("%d", niz[i]);
      printf("\n");
	
    }
    

  return 0;
}
