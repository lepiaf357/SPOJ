#include <cstdio>
#include <unordered_map>
#include <iterator>
using namespace std;

unordered_map<int, int> a;
int racman[500001];

int main()
{
     a[0] = 0;
     racman[0] = 0;
     int prev = 0;
     for (int i = 1; i <= 500000; ++i)
     {
          int temp = prev - i;
          if (temp > 0 && a.find(temp) == a.end())
               a[temp] = i;
          else
          {
               temp = prev +i;
               a[temp] = i;
          }
          racman[i] = temp;
          prev = temp;

     }
     int n;
     scanf("%d", &n);
     while (n != -1)
     {
          printf("%d\n", racman[n]);
          scanf("%d", &n);
     }
     return 0;
}
