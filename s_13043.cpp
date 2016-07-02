#include <cstring>
#include <cstdio>

using namespace std;

char s[100000];

int main()
{
     int t;
     scanf("%d", &t);

     while (t--)
     {
          scanf("%s", &s[0]);
          int n = strlen(s);

          int i, j ;
          for (i = 0, j = n-1; i <= j; ++i, --j)
               if (s[i] != s[j])
                    break;
          if (i < j)
               printf("NO\n\n");
          else
               printf("YES\n\n");

     }
     return 0;
}
