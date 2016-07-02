#include<iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> abc(27);

int main()
{
     char str[1001];

     while(scanf("%s", str) > 0)
     {
          int len = strlen(str);

          vector<char> str1(len);

          for (int i = 0; i < len; i++)
              str1[i] = str[i];

          for (int i = 1; i <= 26; i++)
              abc[i] = 0;

          scanf("%s", str);
          len = strlen(str);

          vector<char>::iterator it;

          for (int i = 0; i < len; i++)
          {
               it = find(str1.begin(), str1.end(), str[i]);
               if (it != str1.end())
               {
                    abc[str[i] - 'a' + 1] += 1;
                    str1.erase(it);
               }
          }

          for (int i = 1; i <= 26; i++)
          {
               while (abc[i] != 0)
               {
                    printf("%c", i + 'a' - 1);
                    abc[i] -= 1;
               }
          }

          printf("\n");

     }

     return 0;
}
