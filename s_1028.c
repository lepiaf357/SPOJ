#include <stdio.h>

int main(void)
{
        int n, winner;

        scanf("%d\n", &n);
        while (n--)
        {
                scanf("%*d%d", &winner);
                if (winner == 0)
                        printf("Airborne wins.\n");
                else
                        printf("Pagfloyd wins.\n");
        }
        return 0;
}
