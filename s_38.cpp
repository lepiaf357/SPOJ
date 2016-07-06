#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
struct Nodes
{
        int v, neighNum;
        int edges[4];//max 4 edges
};
vector<Nodes*> graph;
vector<vector<int>> graph_matrix(1001);

int *visited;
int bfs(int numEdges, int s)
{
        int level = 1;
        queue<int> q;
        visited = (int*) calloc((numEdges+1), sizeof *visited);
        q.push(s);
        visited[s] = level++;
        while (!q.empty())
        {
                int curr = q.front();
                q.pop();
                level = visited[curr];
                // printf("Current node %d:\n", curr);
                for (int i=0; i < graph[curr]->neighNum; ++i)
                {
                        if (visited[graph[curr]->edges[i]] == 0)
                        {
                                // printf(" %d", graph[curr]->edges[i]);
                                q.push(graph[curr]->edges[i]);
                                visited[graph[curr]->edges[i]] = level+1;
                        }
                        // printf("\n");

                }
        }

        int Max = visited[1], index = 1;
        for (int i = 2; i <= numEdges; i++)
                if (Max < visited[i])
                {
                        Max = visited[i];
                        index = i;
                }
        return index;
}

int main()
{
        int t, n, m;

        scanf("%d", &t);

        while(t--)
        {
                scanf("%d%d", &m, &n);
                for (int i=0, current=1; i<n; i++)//read the input graph. # is given number 0, others are given consecutive numbers
                {
                        char temp;
                        scanf(" %c", &temp);
                        if (temp == '#')
                                graph_matrix[i].push_back(0);
                        else
                                graph_matrix[i].push_back(current++);

                        for (int j=1; j<m; ++j)
                        {
                                scanf("%c", &temp);
                                if (temp == '#')
                                        graph_matrix[i].push_back(0);
                                else
                                        graph_matrix[i].push_back(current++);
                        }
                }
                int lastV = 0;
                graph.push_back(NULL);//the vertices are numbered from 1. This push (NULL) will reserve the zero location
                for (int i=0; i<n; i++)
                {
                        for (int j=0; j<m; ++j)
                                if (graph_matrix[i][j] != 0)
                                {
                                        Nodes *e = (Nodes*) malloc(sizeof *e);
                                        e->v = graph_matrix[i][j];
                                        e->neighNum = 0;
                                        lastV = graph_matrix[i][j];
                                        // graph.push_back(malloc(sizeof Edge))
                                        //go left
                                        if (j > 0 && graph_matrix[i][j-1] != 0)
                                        { e->edges[e->neighNum] = graph_matrix[i][j-1]; e->neighNum++; }
                                        //go right
                                        if (j < m-1 && graph_matrix[i][j+1] != 0)
                                        { e->edges[e->neighNum] = graph_matrix[i][j+1]; e->neighNum++; }
                                        //go down
                                        if (i < n-1 && graph_matrix[i+1][j] != 0)
                                        { e->edges[e->neighNum] = graph_matrix[i+1][j]; e->neighNum++; }
                                        //go up
                                        if (i >0 && graph_matrix[i-1][j] != 0)
                                        { e->edges[e->neighNum] = graph_matrix[i-1][j]; e->neighNum++; }
                                        graph.push_back(e);
                                }
                }
                int maxPathIndex = bfs(lastV, bfs(lastV, 1));
                printf("Maximum rope length is %d.\n", visited[maxPathIndex]-1);

                // for (int i=0; i<lastV; i++)
                // {
                //         printf("%d: ", graph[i]->v);
                //         for (int j=0; j<graph[i]->neighNum; j++)
                //                 printf("%d ", graph[i]->edges[j]);
                //         printf("\n");
                // }

                for (int i=0; i<n; i++)
                        graph_matrix[i].clear();
                graph.clear();



        }
        return 0;
}
