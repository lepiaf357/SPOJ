#include<stack>
#include<iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int n;
  stack<char> s1;

  scanf("%d", &n);
  while (n--)
  {
    char c;
    scanf(" %c", &c);
    while (c != '\n')
    {
            if (c == ')')
            {
                    char next = s1.top();
                    s1.pop();
                    while (next != '(')
                    {
                            printf("%c", next);
                            next = s1.top();
                            s1.pop();
                    }
            }
            else if (c >= 'a' && c <= 'z')
                    printf("%c", c);
            else
                    s1.push(c);
            scanf("%c", &c);
    }
    printf("\n");
  }
  return 0;
}
