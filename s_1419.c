#include <stdio.h>


int main()
{
        int n, m;

        scanf("%d", &n);
        m = n % 10;
        if(m == 0)
                printf("2\n");
        else
                printf("1\n%d\n", m);
        return 0;
}
