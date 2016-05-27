#include <stdio.h>

int main()
{
        int n;

        scanf("%d", &n);

        while(n != -1)
        {
                if((n - 1) % 6 == 0)
                {

                        int beehive_number = (n - 1) / 6;
                        int i, triangle_number;
                        if (n == 1)
                                printf("Y\n");
                        else
                                for (i = 1, triangle_number = 0; ; ++i)
                                {
                                        triangle_number += i;
                                        if (triangle_number == beehive_number)
                                        {
                                                printf("Y\n");
                                                break;
                                        }
                                        if (triangle_number > beehive_number)
                                        {
                                                printf("N\n");
                                                break;
                                        }
                                }

                }
                else
                        printf("N\n");

                scanf("%d", &n);
        }

        return 0;
}
