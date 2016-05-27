#include <cstdio>
#include <queue>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

int bitmap[183][183];
int result[183][183];
int visited[183][183];

int bfs(int n, int m, int x, int y)
{
     queue<int> q;
     q.push(x);
     q.push(y);
     result[x][y] = 0;
     memset(visited, 0, sizeof(visited));
     visited[x][y] = 1;
     while(!q.empty())
     {
          int i = q.front(); q.pop();
          int j = q.front(); q.pop();
          int dist;

          if (i != 0)//up
          {
               if (!visited[i-1][j])
               if (bitmap[i-1][j] != 1)
               {
                    if (abs(x-(i-1))+abs(y-j) < result[i-1][j])//check if smaller or equal
                         //and push it
                    { result[i-1][j] = abs(x-i+1) + abs(y-j); visited[i-1][j] = 1; q.push(i-1); q.push(j); }
               }
               //else nothing
          }
          if (j != 0)
          {
               if (!visited[i][j-1])
               if (bitmap[i][j-1] != 1)
               {
                    if (abs(x-(i))+abs(y-(j-1)) < result[i][j-1])//check if smaller or equal
                         //and push it
                    { result[i][j-1] = abs(x-i) + abs(y-j+1); visited[i][j-1] = 1;q.push(i); q.push(j-1); }
               }
               //else nothing
          }
          if (i != n-1)
          {
               if (!visited[i+1][j])
               if (bitmap[i+1][j] != 1)
               {
                    if (abs(x-(i+1))+abs(y-(j)) < result[i+1][j])//check if smaller or equal
                         //and push it
                    { result[i+1][j] = abs(x-i-1) + abs(y-j); visited[i+1][j] = 1;q.push(i+1); q.push(j); }
               }
          }
          if (j != m-1)
          {
               if (!visited[i][j+1])
               if (bitmap[i][j+1] != 1)
               {
                    if (abs(x-(i))+abs(y-(j+1)) < result[i][j+1])//check if smaller or equal
                         //and push it
                    { result[i][j+1] = abs(x-i) + abs(y-j-1); visited[i][j+1] = 1; q.push(i); q.push(j+1); }
               }
          }

     }
}

int main(void)
{
     int t, n, m;

     scanf("%d", &t);

     while(t--)
     {
          char temp;
          scanf("%d%d", &n, &m);
          for (int i = 0; i < n; i++)
               for (int j = 0; j < m; ++j)
               {
                    scanf(" %c", &temp);
                    bitmap[i][j] = temp - '0';
                    result[i][j] = INT_MAX;
               }
          for (int i = 0; i < n; ++i)
               for (int j = 0; j < m; ++j)
                    if (bitmap[i][j] == 1)
                         bfs(n, m, i, j);
          for (int i = 0; i < n; ++i)
          {
               for (int j = 0; j < m; ++j)
               {
                    printf("%d ", result[i][j]);

               }
               printf("\n");
          }
     }


     return 0;
}
