#include <stdio.h>


int niz[1000001];
int main()
{
        int n;
        scanf("%d", &n);
        while(n > 0)
        {
                int i;
                for(i=1; i<=n; i++)
                        scanf("%d", &niz[i]);

                for(i=1; i<=n; i++)
                        if(niz[niz[i]] != i)
                        {
                                printf("not ambiguous\n");
                                break;
                        }
                if(i == n+1)
                        printf("ambiguous\n");

                scanf("%d", &n);
        }

        return 0;
}
