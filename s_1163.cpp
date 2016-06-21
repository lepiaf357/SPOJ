#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

int main()
{
    char s[101];  
    
    while (scanf("%s", s) >= 0)
    {
        if (!islower(s[0]))
        {
            printf("Error!\n");
            continue;
        }
        
        string str;
        str.push_back(s[0]);
        
        int java = 0, flag = 0;
        int i;
        
        for (i = 1; s[i] != '\0'; i++)
        {           
            if (islower(s[i]))
                str.push_back(s[i]);
            else if (isupper(s[i]))
            {
                java = 1;
                str.push_back('_');
                str.push_back(s[i] + 32);
                break;
            }
            else if (s[i] == '_')
            {
                i++;
                if (islower(s[i]))
                    str.push_back(s[i] - 32);
                else
                {
                    printf("Error!\n");
                    flag = 1;
                }
                break;
            }
            else
            {
                printf("Error!\n");
                flag = 1;
                break;                                                            
            }
        }
        
        if (flag)
            continue;
        if (s[i] == '\0')
        {
            cout << str << endl;
            continue;
        }
        
        i++;
        
        while (s[i] != '\0')
        {
            if (islower(s[i]))
                str.push_back(s[i]);
            else if (isupper(s[i]))
            {
                if (java)
                {
                    str.push_back('_');
                    str.push_back(s[i] + 32);
                }
                else
                {
                    printf("Error!\n");
                    flag = 1;
                    break;
                }
            }
            else if (s[i] == '_')
            {
                if (!java)
                {
                    i++;
                    if (islower(s[i]))
                        str.push_back(s[i] - 32);
                    else
                    {
                        printf("Error!\n");
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    printf("Error!\n");
                    flag = 1;
                    break;
                }
            }
            else
            {
                printf("Error!\n");
                flag = 1;
                break;                    
 
            }
            i++;
        }
        if (!flag)
            cout << str << endl;
    }
    return 0;
}