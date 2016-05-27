#include <stdio.h>

int main(void)
{
        int n, mecha, mechaLen, godzilla, godzillaLen;

        scanf("%d", &n);

        while(n--)
        {
                int i = 1, temp;
                scanf("%d%d", &godzillaLen, &mechaLen);
                scanf("%d", &godzilla);
                for (i = 1; i < godzillaLen; ++i)
                {
                        scanf("%d", &temp);
                        if (temp > godzilla)
                                godzilla = temp;
                }
                scanf("%d", &mecha);
                for (i = 1; i < mechaLen; ++i)
                {
                        scanf("%d", &temp);
                        if (temp > mecha)
                                mecha = temp;
                }
                if (mecha > godzilla)
                        printf("MechaGodzilla\n");
                else
                        printf("Godzilla\n");

        }
        return 0;
}
