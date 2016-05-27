#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

struct list
{
        int v;
        struct list *next;
};

int bfs(struct list **adj, int v, int s, int *dist)
{
        queue<int> q;
        int i, max;
        int *marked = (int*)calloc((v+1),  sizeof *marked);
        q.push(s);
        marked[s] = 1;
        while (!q.empty())
        {
                int next = q.front();
                struct list *temp;
                q.pop();
                temp = adj[next];
                while (temp != NULL)
                {
                        if (!marked[temp->v])
                        {
                                q.push(temp->v);
                                marked[temp->v] = marked[next] + 1;
                        }
                        temp = temp->next;
                }
        }
        max = 1;
        for (i = 2; i <= v; ++i)
                if (marked[i] > marked[max])
                        max = i;
        *dist = marked[max];
        return max;

}

int main()
{
        int v, e, i, dist;
        struct list **adj;
        scanf("%d", &v);
        e = v-1;
        adj = (struct list**)malloc ((v+1) * sizeof *adj);
        for (i = 1; i <= v; ++i)
                adj[i] = NULL;

        for (i = 1; i <= e; ++i)
        {
                int s, d;
                struct list *temp = (struct list*)malloc(sizeof *temp);
                scanf ("%d%d", &s, &d);
                temp -> v = d;
                temp -> next = adj[s];
                adj[s] = temp;
                temp = (struct list*)malloc(sizeof *temp);
                temp -> v = s;
                temp -> next = adj[d];
                adj[d] = temp;

        }
        bfs(adj, v, bfs(adj, v, 1, &dist), &dist);
        printf("%d\n", dist - 1);

        return 0;
}
