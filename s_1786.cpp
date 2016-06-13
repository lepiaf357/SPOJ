#include <cstdio>

int survivor(int n)
{
    if (n == 1)
        return 1;
    
    if (n & 1)
        return 2 * survivor(n/2) + 1;
    else
        return 2 * survivor(n/2) - 1;
}

int main()
{
    int a, b, n;
    int pow[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    
    while(1)
    {
        scanf("%d%*c%d", &a, &b);
        n = a*pow[b];
        
        if (n == 0)
            break;
        else
            printf("%d\n", survivor(n));
    }
    return 0;
}