#include <stdio.h>
#include <math.h>

int main()
{
        float l ;

        scanf("%f", &l);

        while (l != 0.0)
        {
                printf("%.2f\n", (l * l) / (2 * M_PI) );
                scanf("%f", &l);
        }
        return 0;
}
