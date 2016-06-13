#include <stdio.h>

int main()
{
    int n;
    
    scanf("%d", &n);
    while(n != 0)
    {
        int br = 0;
        
        while (n != 1)
        {
            n /= 2;
            br ++;
        }
        
        printf("%d\n", br);
        scanf("%d", &n);
    }
    return 0;
}