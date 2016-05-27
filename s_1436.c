#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

struct list
{
        int v;
        struct list *next;
};

void bfs(struct list **adj, int v)
{
        queue<int> q;
        int i;
        int *marked = (int*)calloc((v+1),  sizeof *marked);
        q.push(1);
        marked[1] = 1;
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
                                marked[temp->v] = 1;
                        }
                        temp = temp->next;
                }
        }
        for (i = 1; i <= v; ++i)
                if (marked[i] == 0)
                {
                        printf("NO");
                        return;
                }
        printf("YES\n");
        return;

}

int main()
{
        int v, e, i;
        struct list **adj;
        scanf("%d%d", &v, &e);
        adj = (struct list**)malloc ((v+1) * sizeof *adj);
        for (i = 1; i <= v; ++i)
                adj[i] = NULL;

        if (v -1 != e)
                printf("NO\n");
        else
        {
                for (i = 1; i <= e; ++i)
                {
                        int s, d;
                        struct list *temp = (struct list*)malloc(sizeof *temp);
                        scanf ("%d%d", &s, &d);
                        temp -> v = d;
                        temp -> next = adj[s];
                        adj[s] = temp;
                }
                bfs(adj, v);

        }
        return 0;
}
