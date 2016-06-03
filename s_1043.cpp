#include <cstdio>
#include <algorithm>
using namespace std;

int a[50001];
int max_prefix[150000];
int max_suffix[150000];
int sum[150000];
int max_sum[150000];

void constructTree(int node, int l, int r)
{
        if (l == r)
                max_prefix[node] = max_suffix[node] = sum[node] = max_sum[node] = a[l];
        else
        {
                int mid = l + (r-l)/2;

                constructTree(2*node+1, l, mid);
                constructTree(2*node+2, mid+1, r);

                sum[node] = sum[2*node+1] + sum[2*node+2];
                max_prefix[node] = max(max_prefix[2*node+1], max_prefix[2*node+2] + sum[2*node + 1]);
                max_suffix[node] = max(max_suffix[2*node+2], max_suffix[2*node+1] + sum[2*node + 2]);
                max_sum[node] = max(max(max_sum[2*node+1], max_sum[2*node+2]), max_prefix[2*node+1] + max_suffix[2*node+2]);
        }
}

int query(int node, int l, int r, int ql, int qr)
{
        if (ql <= l && qr >= r)
                return max_sum[node];
        if (ql > r || qr < l)
                return 0;
        int mid = l + (r-l)/2;
        return query(2*node+1, l, mid, ql, qr) + query(2*node+2, mid+1, r, ql, qr);
}

int main()
{
        int n, m, l, r, i = 0;
        scanf("%d", &n);

        while(n--)
        {
                scanf("%d", &a[i]);
                ++i;
        }
        constructTree(0, 0, i-1);
        scanf("%d", &m);
        while (m--)
        {
                scanf("%d%d", &l, &r);
                printf("%d\n", query(0, 0, i-1, l-1, r-1));
        }
        return 0;
}
