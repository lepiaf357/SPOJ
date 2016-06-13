#include <cstdio>
#include <set>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    int n, m;
    
    scanf("%d", &t);
    
    while (t--)
    {
        scanf("%d", &n);
        
        int tmp;
        int minimum = INT_MAX;
        set<int> skup;
        set<int>::iterator it;
        int flag = 0;
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            skup.insert(tmp);
        }
                
        scanf("%d", &m);
                
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &tmp);
            
            if (skup.find(tmp) != skup.end())
            {
                printf("0\n");
                for (; i < m-1; i++)
                    scanf("%*d");
                flag = 1;
                break;
            }
            else
            {
                skup.insert(tmp);
                it = skup.find(tmp);
                
                if (it != skup.begin())
                {
                    it--;
                    minimum = min(minimum, abs(tmp - *it));
                    it++; 
                }
                
                if (it != skup.end())
                {
                    it++;
                    if (it != skup.end())
                    {
                        minimum = min(minimum, abs(tmp - *it));
                    }
                }
            }
        }
        if (!flag)
        {
            printf("%d\n", minimum);
        }
        
        skup.clear();
        
    }
    return 0;
}