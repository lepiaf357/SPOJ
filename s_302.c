#include <stdio.h>


int main()
{
        int n, br, i, j;

        scanf("%d", &n);

        while(n > 0)
        {
                int f = 0;
                scanf("%d", &br);

                int cnt = 0;
                for(i = 1 ; f == 0 ; i++)

                        for(j = 1; j <= i; j++)
                        {
                                cnt++;
                                if(br == cnt)
                                {
                                        if(i % 2 == 0)
                                                printf("TERM %d IS %d/%d\n", br, j, (i+1)-j);
                                        else
                                                printf("TERM %d IS %d/%d\n", br, (i+1)-j, j);
                                        f = 1;
                                        break;
                                }
                        }

                n--;

        }

        return 0;
}
