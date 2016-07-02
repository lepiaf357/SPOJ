#include <cstdio>
#include <deque>

using namespace std;

int a[1000000];

int main()
{

     int n, k;

     scanf("%d", &n);
     for (int i = 0; i < n; i++)
          scanf("%d", &a[i]);

     scanf("%d", &k);
     deque<int> d;
     for (int i = 0; i < k; i++)
     {
          while (!d.empty() && d.back() < a[i])
               d.pop_back();
          d.push_back(a[i]);
     }
     printf("%d ", d.front());
     for (int i = k, j = 0; i < n; ++i, ++j)
     {
          if (a[j] == d.front())
               d.pop_front();
          while (!d.empty() && d.back() < a[i])
               d.pop_back();
          d.push_back(a[i]);
          printf("%d ", d.front());
     }
     printf("\n");
     return 0;
}
