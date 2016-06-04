#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

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
                max_sum[node] = max(max(max_sum[2*node+1], max_sum[2*node+2]), max_suffix[2*node+1] + max_prefix[2*node+2]);
        }
}

void queryNodes(vector<int> &nodes, int node, int l, int r, int ql, int qr)
{
        if (ql <= l && qr >= r)
                nodes.push_back(node);
        else if (ql > r || qr < l)
                return ;
        else
        {
                int mid = l + (r-l)/2;
                queryNodes(nodes, 2*node+1, l, mid, ql, qr);
                queryNodes(nodes, 2*node+2, mid+1, r, ql, qr);
        }
}
int query(int n, int l, int r)
{
        vector<int> nodes;
        queryNodes(nodes, 0, 0, n, l, r);
        int res, temp;
        // for (int i = 0; i < nodes.size(); ++i)
        //         printf("%d ", nodes[i]);
        // printf("\n");
        res = max_sum[nodes[0]];
        res = max(res, max_prefix[nodes[0]]);
        temp = max(sum[nodes[0]], max_suffix[nodes[0]]);
        for (int i = 1; i < nodes.size(); ++i)
        {
                res = max(res, max_sum[nodes[i]]);
                res = max(res, temp + max_prefix[nodes[i]]);
                temp = max(temp + sum[nodes[i]], max_suffix[nodes[i]]);
        }
        return res;
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
                printf("%d\n", query(i-1, l-1, r-1));
        }
        return 0;
}
