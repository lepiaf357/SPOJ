#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int sum_r(vector<vector <int> > &graph, int i, int j)
{
    if (i == n-1)
      if (j == 0 && graph[i][j] < 0)
        return graph[i][j] + graph[i][1];
    else
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
    vector<vector <int> > tab(n, vector<int>(3));

    if (graph[n-1][0] < 0)
      tab[n-1][0] = graph[n-1][1] + graph[n-1][0];
    else
      tab[n-1][0] = graph[n-1][1];

    tab[n-1][1] = graph[n-1][1];
    tab[n-1][2] = graph[n-1][1];

    for (int i = n-2; i >= 0; i--)
    {
      tab[i][2] = min(tab[i+1][1], tab[i+1][2]) + graph[i][2];
      tab[i][1] = min(min(tab[i+1][1], tab[i+1][0]), min(tab[i+1][2], tab[i][2])) + graph[i][1];
      tab[i][0] = min(tab[i+1][0], min(tab[i+1][1], tab[i][1])) + graph[i][0];
    }

    return tab[0][1];
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

         printf("%d. %d\n", br, sum(graph));
     }

     return 0;
}
