#include <cstdio>

void minus_2(int * a, int n)
{
     if (a[n] >= 2)
     {
         a[n] -= 2;
         return;
     }
     
     a[n] += 8;
     for (int i = n-1; i >= 0; i--)
     {
          if (a[i] == 0)
              a[i] = 9;
          else
          {
              a[i] -= 1;
              break;
          }
     }
}

void mul_2(int * a, int n, int *ret)
{
     int tmp;
     for (int i = 1; i <= n; i++)
     {
         tmp = a[i] * 2;
         if (tmp >= 10)
         {
             ret[i] = tmp % 10;
             ret[i-1] += 1; 
         }
         else
             ret[i] = tmp;
     }
}

int main()
{
    int num[102], ret[102], ret2[102];
    char c;
    int flag = 0;
    
    while (1)
    {   
        int len = 0;
        while (1)
        {
            c = getchar();
            
            if (c == '\n')
                break;
            else if (c >= '0' && c <= '9')
            {
                num[len + 1] = c - '0';
                len++;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        
        if (flag)
            break;
        
        if (len == 1)
        {
            if (num[1] == 1)
            {
                printf("1\n");
                continue;
            }
            else if (num[1] == 0)
            {
                printf("0\n");
                continue;
            }
        }
        
        num[0] = 0;
        ret[0] = 0;
        
        mul_2(num, len, ret); 
        minus_2(ret, len);
        
        if (ret[0] != 0)
            printf("%d", ret[0]);
        for (int i = 1; i <= len; i++)
            printf("%d", ret[i]);
        
        printf("\n");
    }
    
    return 0;
}