#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
     map<string, int> mm;
     map<string, int>::iterator it;
     int t;
     int n;

     scanf("%d", &t);

     while (t--)
     {
          scanf("%d", &n);
          string s;
          getline(cin, s);
          for (int i = 0; i < n; i++)
          {
               getline(cin, s);

               if (mm.find(s) != mm.end())
               {
                    mm[s] = mm[s] + 1;
               }
               else
               {
                    mm.insert(pair<string, int>(s, 1));
               }

               // cout << mm.find(s)->first << " " << mm[s] << endl;
          }

          for (it = mm.begin(); it != mm.end(); it++)
          {
               cout << it->first;
               printf(" %d\n", it->second);
          }
          printf("\n");
          mm.clear();
     }
     return 0;
}
