#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int cells, exit, timer;
    int a[101][101];
    int m;

    scanf("%d%d%d", &cells, &exit, &timer);
    scanf("%d", &m);
    
    memset(a, , sizeof(a)); //
    
    int t1, t2, t3;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &t1, &t2, &t3);
        a[t1][t2] = t3;
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min (a[i][j], a[i][k]+a[k][j]);
            
    
    return 0;
}