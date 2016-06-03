#include <stdio.h>

int main()
{
    int t, a, b, i, br, tmp;
    
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d%d", &a, &b);
        
        while (b != 0)
        {
            tmp = a;
            a = b;
            b = tmp % b; 
        }
        
        br = 2;
        for (i = 2; i*i <= a; i++)
        {
            if (a % i == 0)
            {
                br += 2;
            }
        }  
        
        if ((i - 1)*(i - 1) == a)
        {
            br--;
        }
        
        printf("%d\n", br);
    }
    
	return 0;
}
