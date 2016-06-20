// Segment Tree practice room 1
// Find the max element in range
// 1) Update the tree in range
// 2) Query the result in range

// Complexity
// Build tree: O(N lg N)
// Update tree: O(N lg(N+k))
// Query tree: O(N lg(N+k))

//Also added functions for lazy propagation

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tree[300000];
int lazy[300000];
int a[100000];

void buildST(int node, int l, int r)
{
        if (l > r)
                return ;
        if (l == r)
        {
                tree[node] = a[l];
                return;
        }
        int mid = l + (r - l) / 2;
        buildST(2*node+1, l, mid); buildST(2*node+2, mid+1, r);
        tree[node] = max(tree [2*node+1], tree [2*node+2]);
}
void updateSTLazy(int node, int l, int r, int ql, int qr, int val)
{
        if (l > r)
                return ;
        if (lazy[node] != 0)
        {
                tree[node] += lazy[node];
                if (l != r)
                {
                        lazy[2*node + 1] += lazy[node];
                        lazy[2*node + 2] += lazy[node];
                }
                lazy[node] = 0;
        }
        if (ql > r || qr < l)
                return ;

        if (ql <= l && qr >= r)
        {
                tree[node] += val;
                if (l != r)
                {
                        lazy[2*node + 1] = val;
                        lazy[2*node + 2] = val;
                }
                return ;
        }

        int mid = l + (r - l) / 2;
        updateSTLazy(2*node + 1, l, mid, ql, qr, val);
        updateSTLazy(2*node + 2, mid+1, r, ql, qr, val);
        tree[node] = max(tree[2*node + 1], tree[2*node + 2]);

}
void updateST(int node, int l, int r, int ql, int qr, int val)
{
        if (l > r || ql > r || qr < l)
                return ;
        if (l == r)
        {
                tree[node] += val;
                return ;
        }
        int mid = l + (r - l) / 2;
        updateST(2*node+1, l, mid, ql, qr, val);
        updateST(2*node+2, mid+1, r, ql, qr, val);
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
}
int querySTLazy(int node, int l, int r, int ql, int qr)
{
        if (l > r)
                return 0;
        if (lazy[node] != 0)
        {
                tree[node] += lazy[node];
                if (l != r)
                {
                        lazy[2*node + 1] = lazy[node];
                        lazy[2*node + 2] = lazy[node];
                }
                lazy[node] = 0;
        }
        if (ql > r || qr < l)
                return 0;
        if (ql <= l && qr >= r)
                return tree[node];
        int mid = l + (r - l) / 2;
        return max(querySTLazy(2*node+1, l, mid, ql, qr), querySTLazy(2*node+2, mid+1, r, ql, qr));

}

int queryST(int node, int l, int r, int ql, int qr)
{
        if (l > r || ql > r || qr < l)
                return 0;
        if (ql <= l && qr >= r)
                return tree[node];

        int mid = l + (r - l) / 2;
        return max(queryST(2*node + 1, l, mid, ql, qr),queryST(2*node + 2, mid+1, r, ql, qr));
}

int main()
{
        const int n = 100;
        for (int i=0; i < n; ++i)
                a[i] = 1;
        buildST(0, 0, n-1);
        memset(lazy, 0, n * sizeof *lazy);
        updateST(0, 0, n-1, 0, 6, 5);
        updateST(0, 0, n-1, 7, 10, 12);
        updateST(0, 0, n-1, 10, n-1, 100);

        printf("%d\n", queryST(0, 0, n-1, 0, 6));
        return 0;
}
