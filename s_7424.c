#include <stdio.h>


int main(void)
{
        int girl, boy;

        scanf("%d%d", &girl, &boy);
        while (girl != -1)
        {
                if (girl == 0 && boy == 0)
                        printf("0\n");
                else if (girl == boy)
                        printf("1\n");
                else
                {
                        if (girl == 0)
                                printf("%d\n", boy);
                        else if (boy == 0)
                                printf("%d\n", girl);
                        else
                        {
                                int res, bigger, smaller;
                                if (girl > boy)
                                {
                                        bigger = girl;
                                        smaller = boy;
                                }
                                else
                                {
                                        bigger = boy;
                                        smaller = girl;
                                }


                                printf("%d\n", (bigger-1) / (smaller+1) + 1);
                        }
                }
                scanf("%d%d", &girl, &boy);
        }
        return 0;
}
