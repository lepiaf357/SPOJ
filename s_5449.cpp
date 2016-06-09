#include <cstdio>
#include <cstring>

int main()
{
    char s[2001];
    int j = 1;
    
    scanf("%s", s);

    while (s[0] != '-')
    {
        int Lbr = 0, Dbr = 0;
        int br = 0;
        
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == '}')
            {
                if (Dbr == 0)
                {
                    Dbr = 1;
                    br++;
                }
                else
                {
                    Dbr--;;
                }
            }
            else
            {
                Dbr++;
            }
        }
        
        br = br + Dbr / 2;
        
        printf("%d. %d\n", j, br);
        j++;
        
        scanf("%s", s);
    }
    
    return 0;
}