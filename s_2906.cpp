#include <cstdio>
#include <iostream>
#include <string>

using namespace std;



int gcd(int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    string s;
    int a;
    int t;
    
    scanf("%d", &t);

    while (t--)
    {
        int tmp = 0, num, b;
          
        scanf("%d", &a);
        cin >> s;
    
        if (a == 0)
        {
            cout << s << endl;
            continue;
        }
        
        int i = 0;
        num = s[i] - '0';
        tmp = num;
        while (tmp % a == tmp)
        {
            i++;
            num = s[i] - '0';
            tmp = tmp * 10 + num;
        }
        b = tmp % a;
        i++;
    
        for (; s[i] != '\0'; i++)
        {
            num = s[i] - '0';
            tmp = b * 10 + num;
            b = tmp % a;
        }
    
        int res = gcd(a,b);
        printf("%d\n", res);
    }
    return 0;
}
