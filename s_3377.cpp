#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

int b = 2;

typedef struct bug_g
{
     int v;
     struct bug_g *next;
} bug;

bug *bugs[2001];
int color[2001];

int bipartite(int s)
{
     queue<int> q;
     q.push(s);
     b = 0;
     color[s] = b;
     while(!q.empty())
     {
          int curr = q.front();
          bug * temp = bugs[curr];
          q.pop();

          while(temp != NULL)
          {
               b = (color[curr]+1) % 2;

               if (color[temp->v] == 2)
               {
                    color[temp->v] = b;
                    q.push(temp->v);
               }
               else if (color[temp->v] == (b+1) % 2)
               {
                    // printf("%d %d b:%d color:%d\n", curr, temp->v, (b+1)%2, color[temp->v]);
                    return -1;
               }
               temp = temp->next;
          }
     }
     return 1;
}

int main()
{
     int n, k, t;

     scanf("%d", &n);
     for (int i = 1; i <= n; ++i)
     {
          scanf("%d%d", &k, &t);
          b = 2;
          for (int j = 1; j <= k; ++j)
          {
               bugs[j] = NULL;
               color[j] = b;
          }

          for (int j = 0; j < t; ++j)
          {
               int n1, n2;
               scanf("%d%d", &n1, &n2);
               bug *node = (bug*) malloc(sizeof *node);
               node->v = n2;
               node->next = bugs[n1];
               bugs[n1] = node;
               node = (bug*) malloc(sizeof *node);
               node->v = n1;
               node->next = bugs[n2];
               bugs[n2] = node;
          }
          // for (int j = 1; j <= k; ++j)
          // {
          //      bug* temp = bugs[j];
          //      printf("%d: ", j);
          //      while (temp != NULL)
          //      {
          //           printf("%d ", temp->v);
          //           temp = temp -> next;
          //      }
          //      printf("\n");
          // }
          int result;
          if (t > (k*k) / 4)
               result = -1;
          else
          {
               for (int j = 1; j <= k; ++j)
               {
                    if (color[j] == 2)
                         result = bipartite(j);
                    if (result == -1)
                         break;
               }
          }


          if (result == -1)
               printf("Scenario #%d:\nSuspicious bugs found!\n", i);
          else
               printf("Scenario #%d:\nNo suspicious bugs found!\n", i);
          }

     return 0;
}
