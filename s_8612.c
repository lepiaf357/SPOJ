#include <stdio.h>
#include <string.h>

// TTT, TTH, THT, THH, HTT, HTH, HHT and HHH.

int compare(char *str)
{
        if (!strncmp(str, "TTT", 3))
                return 0;
        if (!strncmp(str, "TTH", 3))
                return 1;
        if (!strncmp(str, "THT", 3))
                return 2;
        if (!strncmp(str, "THH", 3))
                return 3;
        if (!strncmp(str, "HTT", 3))
                return 4;
        if (!strncmp(str, "HTH", 3))
                return 5;
        if (!strncmp(str, "HHT", 3))
                return 6;
        if (!strncmp(str, "HHH", 3))
                return 7;
}

int main()
{
        int n, t, len;
        char hth[41];
        int result[8];
        scanf("%d", &n);

        while(n--)
        {
                int i, j;
                for (i = 0; i < 8; ++i)
                        result[i] = 0;
                scanf("%d", &t);
                scanf("%s", hth);
                for (i = 0; i < 38; ++i)
                        result[compare(&hth[i])]++;

                printf("%d ", t);
                for (i = 0; i < 8; ++i)
                        printf("%d ", result[i]);
                printf("\n");
        }

        return 0;


}
