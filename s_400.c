#include <stdio.h>


int main()
{
  int col, row, num;
  char mes[200];

  scanf("%d", &col);
  getchar();
  
  while(col != 0)
    {
      char c;
      int i, j;

      num = 0;     
      while( (c = getchar()) != '\n')
	{
	  mes[num++] = c;
	}
      num--;

      row = (num+1) / col;

      
      for(i = 0; i < col ; i++)
	{
	  for(j = 0; j < row; j++)
	    {
	      if( j % 2 == 0)
	        printf("%c", mes[i + j*col]);
	      else
		printf("%c", mes[j*col + col - i -1]);
	    }
	} 
      printf("\n");
      scanf("%d", &col);
    }

  
  return 0; 
}
