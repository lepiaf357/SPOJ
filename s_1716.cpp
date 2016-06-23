#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a(50001);
int max_prefix[150000];
int max_suffix[150000];
int sum[150000];
int max_sum[150000];

void segmentTree(int node, int l, int r)
{
        if (l == r)
            sum[node] = max_prefix[node] = max_suffix[node] = max_sum[node] = a[l];
        else
        {
            int mid = l + (r-l)/2;

            segmentTree(2*node+1, l, mid);
            segmentTree(2*node+2, mid+1, r);

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
                return;
        else
        {
            int mid = l + (r-l)/2;
            queryNodes(nodes, 2*node+1, l, mid, ql, qr);
            queryNodes(nodes, 2*node+2, mid+1, r, ql, qr);
        }
}

int maxSum(int n, int l, int r)
{
        vector<int> nodes;
        queryNodes(nodes, 0, 0, n, l, r);
        
        int res, temp;
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

void changeNode(int node, int l, int r, int ch)
{
        if (ch < l || ch > r)
            return;
        
        if (l == r)
            sum[node] = max_prefix[node] = max_suffix[node] = max_sum[node] = a[l];

        else
        {
            int mid = l + (r-l)/2;

            changeNode(2*node+1, l, mid, ch);
            changeNode(2*node+2, mid+1, r, ch);

            sum[node] = sum[2*node+1] + sum[2*node+2];
            max_prefix[node] = max(max_prefix[2*node+1], max_prefix[2*node+2] + sum[2*node + 1]);
            max_suffix[node] = max(max_suffix[2*node+2], max_suffix[2*node+1] + sum[2*node + 2]);
            max_sum[node] = max(max(max_sum[2*node+1], max_sum[2*node+2]), max_suffix[2*node+1] + max_prefix[2*node+2]);
        }
}

int main()
{
    int n, m;
    int t;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        a[i] = t;
    }
    
    segmentTree(0, 0, n-1);
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int b, x, y;
        scanf("%d%d%d", &b, &x, &y);
        
        if (b == 0)
        {
            a[x-1] = y;
            changeNode(0,0, n-1, x-1);
        }
        else
        {
            printf("%d\n", maxSum(n-1, x-1, y-1));
        }
    }
    
    return 0;
}
