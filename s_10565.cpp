#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
     int t, n;

     scanf("%d", &t);
     while (t--)
     {
          scanf("%d", &n);
          printf("%d\n", (n-1)/2 + 1);
     }
     return 0;
}
