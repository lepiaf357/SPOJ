#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

long long tree[300000];
long long lazy[300000];

void updateST(int node, int l, int r, int ql, int qr, long long val)
{
        if (qr < l || ql > r || l > r)
                return ;
        if (l == r)
        {
                tree[node] += val;
                return;
        }


        int mid = l + (r - l) / 2;
        updateST(2*node+1, l, mid, ql, qr, val);
        updateST(2*node+2, mid+1, r, ql, qr, val);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

void updateSTLazy(int node, int l, int r, int ql, int qr, long long val)
{
        if (l > r)
                return ;
        if (lazy[node] != 0)
        {
                tree[node] += (r - l + 1) * lazy[node];
                if (l != r)
                {
                        lazy[2*node + 1] += lazy[node];
                        lazy[2*node + 2] += lazy[node];
                }
                lazy[node] = 0;
        }
        if (qr < l || ql > r )
                return;
        if (ql <= l && qr >= r)//fully in range of requested
        {
                tree[node] += (r - l + 1)*val;
                if (l != r)
                {
                        lazy[2*node + 1] += val;
                        lazy[2*node + 2] += val;
                }
                return ;
        }

        int mid = l + (r - l) / 2;

        updateSTLazy(2*node+1, l, mid, ql, qr, val);
        updateSTLazy(2*node+2, mid+1, r, ql, qr, val);
        tree[node] = tree[2*node+1] + tree[2*node + 2];
}
long long querySTLazy(int node, int l, int r, int ql, int qr)
{
        if (ql > r || qr < l)
                return 0;
        if (lazy[node] != 0)
        {
                tree[node] += (r-l+1) * lazy[node];
                if (l != r)
                {
                        lazy[2*node + 1] += lazy[node];
                        lazy[2*node + 2] += lazy[node];
                }
                lazy[node] = 0;
        }

        if (ql <= l && qr >= r)
                return tree[node];
        int mid = l + (r - l) / 2;
        return querySTLazy(2*node+1, l, mid, ql, qr) + querySTLazy(2*node+2, mid+1, r, ql, qr);
}
long long queryST(int node, int l, int r, int ql, int qr)
{
        if (ql > r || qr < l)
                return 0;
        if (ql <= l && qr >= r)
                return tree[node];
        int mid = l + (r - l) / 2;

        return queryST(2*node+1, l, mid, ql, qr) + queryST(2*node+2, mid+1, r, ql, qr);
}

int main()
{
        int t, n, c;

        scanf("%d", &t);
        while(t--)
        {
                scanf("%d%d", &n, &c);
                int depth = ceil(log2(n));
                depth = 2 * (int)pow(2, depth);
                int count;
                memset(tree, 0, depth * sizeof *tree);
                memset(lazy, 0, depth * sizeof *lazy);
                for (int i = 0; i < c; ++i)
                {
                        int operation;
                        scanf("%d", &operation);
                        if (!operation)//update
                        {
                                int l, r;
                                long long val;
                                scanf("%d%d%lld", &l, &r, &val);
                                --l; --r;
                                updateSTLazy(0, 0, n-1, l, r, val);
                        }
                        else//query
                        {
                                int l, r;
                                scanf("%d%d", &l, &r);
                                --l; --r;
                                printf("%lld\n", querySTLazy(0, 0, n-1, l, r));
                        }
                }
        }
        return 0;

}
