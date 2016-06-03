#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main ()
{
     set<int> myset;
     set<int>::iterator it;
     int n, fnum, f;
     int i, j;
     
     scanf("%d", &n);
     
     for (i = 0; i < n; i++)
     {
         scanf("%d%d", &f, &fnum);
         myset.insert(f);
         for (j = 0; j < fnum; j++)
         {
             scanf("%d", &f);
             myset.insert(f);
         }
     }
     int size = myset.size() - n;
     printf("%d\n", size);
     
    return 0;
}