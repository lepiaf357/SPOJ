#include <stdio.h>

int compare(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

int main()
{
        int n, sum, len, br = 1;
        int people[10000];

        scanf("%d", &n);
        while(n>0)
        {
                int i;
                scanf("%d%d", &sum, &len);

                for(i=0; i<len; i++)
                        scanf("%d", &people[i]);

                qsort(people, len, sizeof(people[0]), &compare);


                for(i=len-1; i >= 0 && sum > 0; i--)
                {
                        sum-=people[i];
                }

                if(sum <= 0)
                        printf("Scenario #%d:\n%d\n\n", br, len - i - 1);
                else
                        printf("Scenario #%d:\nimpossible\n\n", br);
                n--;
                br++;
        }
        return 0;
}
