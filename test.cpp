#include <iostream>
#include<cstdio>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
     vector<string> strvec;
     int n, i;
     string strin;
     char st[11];
     int t;

     scanf("%d", &t);

     while (t != 0)
     {
          int f = 0;
          scanf("%d", &n);
          for(i = 0; i < n; i++)
          {
               // scanf("%s", st); strin = st;
               cin >> strin;
               strvec.push_back(strin);
          }
          sort(strvec.begin(), strvec.end());

          for(i = 0; i < n-1; i++)
          {
               if(strvec[i+1].size() < strvec[i].size())
               {
                    // if(strvec[i+1].compare(strvec[i].substr(0, strvec[i+1].size())) == 0)
                    // {
                    //      cout << "NO" << endl;
                    //      f = 1;
                    //      break;
                    // }
                    continue;
               }
               else
               {
                    if(strvec[i].compare(strvec[i+1].substr(0, strvec[i].size())) == 0)
                    {
                         cout << "NO" << endl;
                         f = 1;
                         break;
                    }
               }

          }
          if (f == 0)
          {
               cout << "YES" << endl;
          }
         strvec.clear();
          t--;
     }

     return 0;
}
