#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

int primes[10000];
int visited[10000];

struct primeList
{
        int p;
        primeList *next;
};
void generatePrimes()
{
        int k = sqrt(10000);
        memset(primes, 1, sizeof primes);
        for (int i=2; i <= k; ++i)
                if (primes[i])
                        for (int j=i; j*i < 10000; ++j)
                                primes[i*j] = 0;
}

void addToList(int a, primeList **list)
{
        primeList *temp;
        temp = (primeList*) malloc(sizeof *temp);

        temp->p = a;
        temp->next = *list;
        *list = temp;
}

primeList *nextLevel(int curr)
{
        primeList *list = NULL;
        int a = curr % 10;
        int b = (curr - a) % 100;
        int c = (curr - a - b) % 1000;
        int d = (curr - a - b - c) % 10000;

        int x = curr - a;
        int y = curr - b;
        int z = curr - c;
        int k = curr - d;
        for (int i = 0; i < 9; ++i)
        {
                a = (a + 1) % 10;
                b = (b + 10) % 100;
                c = (c + 100) % 1000;
                d = (d + 1000) % 10000;

                if (primes[x+a])
                        addToList(x+a, &list);
                if (primes[y+b])
                        addToList(y+b, &list);
                if (primes[z+c])
                        addToList(z+c, &list);
                if (d != 0 && primes[k+d])
                        addToList(k+d, &list);
        }
        return list;
}

void clear( std::queue<int> &q )
{
        std::queue<int> empty;
        std::swap( q, empty );
}

int main()
{
        int n, s, p;
        scanf("%d", &n);

        generatePrimes();
        while(n--)
        {
                queue<int> q;
                int level = 0;
                memset(visited, -1, sizeof visited);
                scanf("%d%d", &s, &p);
                q.push(s);
                visited[s] = 0;
                while (!q.empty())
                {
                        int curr = q.front();
                        q.pop();
                        level = visited[curr] + 1;
                        if (curr == p)
                                break;
                        primeList *neigh = nextLevel(curr);
                        while(neigh != NULL)
                        {
                                if (visited[neigh->p] == -1)
                                {
                                        visited[neigh->p] = level;
                                        q.push(neigh->p);
                                }
                                neigh = neigh->next;
                        }
                }
                printf("%d\n", visited[p]);
                clear(q);
        }
        return 0;
}
