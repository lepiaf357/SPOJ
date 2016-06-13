#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int sum_r(vector<vector <int> > &graph, int i, int j)
{
    if (i == n-1)
        return graph[i][1];

    if (j == 0)
        return min(sum_r(graph, i+1, j), min(sum_r(graph, i+1, j+1), sum_r(graph, i, j+1))) + graph[i][j];
    else if (j == 1)
        return min(min(sum_r(graph, i+1, j), sum_r(graph, i+1, j-1)), min(sum_r(graph, i+1, j+1), sum_r(graph, i, j+1))) + graph[i][j];
    else if (j == 2)
        return min(sum_r(graph, i+1, j-1), sum_r(graph, i+1, j)) + graph[i][j];
        
}

int sum(vector<vector <int> > &graph)
{
    int first = 1;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
        {
            if (first)
            {
                j = 1;
                first = 0;
            }
            
            ....
        }
}

int main()
{
     int t, br = 0;
     
     while (1)
     {
          br++;
          scanf("%d", &n);
          
          if (n == 0)
              break;
                    
          vector<vector <int> > graph(n, vector<int>(3));

          for (int i = 0; i < n; i++)
              for (int j = 0; j < 3; j++)
              {
                  scanf("%d", &t);
                  graph[i][j] = t;
              }
              
         printf("%d. %d", br, sum_r(graph, 0, 1));
     }
      
     return 0;
}


